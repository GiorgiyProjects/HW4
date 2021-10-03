#pragma once
#include "Shape.h"
#include <string>
#include <vector>

using namespace std;
class Document
{
    string mName;
    vector<Shape> mShapes;
    int mId;
public:
    Document(string name)
    {
        mName = name;
    }

    string GetName()
    {
        return mName;
    }

    void SetId(int id)
    {
        mId = id;
    }

    int GetId()
    {
        return mId;
    }

    void AddShape(Shape* sh)
    {
        mShapes.push_back(*sh);
        sh->SetId(mShapes.size());
    }

    bool DeleteShape(int id)
    {
        int idx = -1;
        for(int i = 0; i < mShapes.size(); i++)
        {
            if (mShapes[i].GetId() == id)
                idx = i;
        }
        if (idx == -1) return false;
        mShapes.erase(mShapes.begin() + idx);
        return true;
    }
};

class Model
{
    vector<Document> mDocs;
public:

    bool CheckIfDocExists(string name)
    {
        for (auto& d:mDocs)
        {
            if (d.GetName() == name) return true;
        }
        return false;
    }

    //returns doc id
    int AddDoc(string name)
    {
        Document D(name);
        D.SetId(mDocs.size());
        mDocs.push_back(D);
        return D.GetId();
    }

    bool AddShapeToDoc(int id, Shape* sh)
    {
        if (id > mDocs.size()) return false;
        mDocs[id].AddShape(sh);
        return true;
    }

    bool DeleteShape(int id, int sh_id)
    {
        if (id > mDocs.size()) return false;
        return mDocs[id].DeleteShape(sh_id);
    }
};