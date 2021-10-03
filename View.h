#pragma once

using namespace std;
#include <iostream>
#include "Controller.h"

Controller C;
// command line interface commands
enum class CLI
{
    exit = 'e',
    create_doc = 'c',
    import_doc = 'i',
    export_doc = 'x',
    add_shape = 's',
    del_shape = 'd',
    help = '?'
};

class View
{
public:
    void EventListener()
    {
        PrintCommands();
        char cmd;
        while (cout << "Enter command:\n" && cin >> cmd && cmd != static_cast<char>(CLI::exit))
        {
            switch (static_cast<CLI>(cmd))
            {
                case CLI::create_doc: CreateDoc();
                    break;

                case CLI::import_doc: ImportDoc();
                    break;

                case CLI::export_doc: ExportDoc();
                    break;

                case CLI::add_shape: CreateShape();
                    break;

                case CLI::del_shape: DeleteShape();
                    break;

                case CLI::help: PrintCommands();
                    break;

                default: cout << "Unknown command\n";
            }
        }
        cout << "Exit\n";
    }

private:
    void PrintCommands(void)
    {
        cout << static_cast<char>(CLI::exit) << " - exit program\n";
        cout << static_cast<char>(CLI::create_doc) << " - create document\n";
        cout << static_cast<char>(CLI::import_doc) << " - import document\n";
        cout << static_cast<char>(CLI::export_doc) << " - export document\n";
        cout << static_cast<char>(CLI::add_shape) << " - add shape\n";
        cout << static_cast<char>(CLI::del_shape) << " - delete shape\n";
        cout << static_cast<char>(CLI::help) << " - print commands list\n";
    }

    void CreateDoc()
    {
        cout << "Enter Document name: " << endl;
        string doc_name = "";
        cin >> doc_name;
        string status = C.TryCreateDoc(doc_name);
        cout << status << endl;
        if (status != "OK") cout << "Failed to create new doc!" << endl;

    }

    void ImportDoc()
    {
        cout << "Enter Document name: " << endl;
        string doc_name = "";
        cin >> doc_name;
        string status = C.TryImportDoc(doc_name);
        cout << status << endl;
        if (status != "OK") cout << "Failed to import doc!" << endl;
    }

    void ExportDoc()
    {
        cout << "Enter Document name: " << endl;
        string doc_name = "";
        cin >> doc_name;
        string status = C.TryExportDoc(doc_name);
        cout << status << endl;
        if (status != "OK") cout << "Failed to export doc!" << endl;
    }

    void CreateShape() {
        cout << "Enter shape type: " << endl;
        cout << static_cast<char>(ShapeType::circle) << " - circle\n";
        cout << static_cast<char>(ShapeType::square) << " - square\n";
        char shape_type;
        cin >> shape_type;
        Shape* sh;

        switch (static_cast<ShapeType>(shape_type)) {
            case ShapeType::circle:
                sh = new Circle();
                sh->RequestParams();
                break;
            case ShapeType::square:
                sh = new Square();
                sh->RequestParams();
                break;
            default: cout << "Unknown shape\n";
        }

        string status = C.TryAddShape(sh);
        cout << status << endl;
        if (status != "OK") cout << "Failed to add shape!" << endl;
    }

    void DeleteShape()
    {
        cout << "Enter shape id: " << endl;
        int id;
        cin >> id;
        string status = C.TryDeleteShape(id);
        cout << status << endl;
        if (status != "OK") cout << "Failed to delete shape!" << endl;
    }


};