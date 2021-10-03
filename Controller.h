#pragma once
#include "Model.h"
#include <iostream>

using namespace std;

Model M;
class Controller
{
    int mCurDocId = -1;
public:

    string TryCreateDoc(string doc_name)
    {
        bool f = M.CheckIfDocExists(doc_name);
        if (f) return "That name is used for another doc!";
        mCurDocId = M.AddDoc(doc_name);
        return "OK";
    }

    string TryImportDoc(string file_name)
    {
        cout << "Controller reads doc contents from a file" << endl;
        //assume doc name will become file name
        return TryCreateDoc(file_name);
    }

    string TryExportDoc(string doc_name)
    {
        if (mCurDocId == -1) return "No document to export";
    }

    string TryAddShape(Shape* sh)
    {
        if (mCurDocId == -1) return "Create doc first";
        bool ret = M.AddShapeToDoc(mCurDocId, sh);
        if (!ret) return "Something went wrong";
        cout << "Added shape with id " + to_string(sh->GetId());
        return ("OK");
    }

    string TryDeleteShape(int id)
    {
        bool ret = M.DeleteShape(mCurDocId, id);
        if (!ret) return "Something went wrong";
        cout << "Deleted shape with id" + to_string(id);
        return ("OK");
    }

};