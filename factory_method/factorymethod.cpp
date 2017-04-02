#include <stdio.h>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class Document {
public:
	virtual bool open(char* pFileName) = 0;
};

class HwpDocument : public Document {
public:
	bool open(char* pFileName) {
		printf("HWP: open %s file\n", pFileName?pFileName:"");
		return true;
	}
};

class MsWordDocument : public Document {
public:
	bool open(char* pFileName) {
		printf("MS Word: open %s file\n", pFileName?pFileName:"");
		return true;
	}
};

class Application {
public:
	void NewDocument(char* pFileName) {
		Document* pDoc = CreateDocument();	// Factory Method
		docs_[pFileName] = pDoc;
		pDoc->open(pFileName);
	}

	virtual Document* CreateDocument() = 0;

private:
	map<string, Document*> docs_;
};

class HwpApplication : public Application {
public:
	Document* CreateDocument() {
		return new HwpDocument;
	}
};

class MsWordApplication : public Application {
public:
	Document* CreateDocument() {
		return new MsWordDocument;
	}
};

int main(int argc, char** argv)
{
	printf("Factory Method Pattern\n");

	HwpApplication hwp;
	hwp.NewDocument((char*)"input.hwp");
}
