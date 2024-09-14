/*

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

class Interpreter
{
public:
    void run(const std::string &code)
    {
        std::istringstream stream(code);
        std::string line;
        while (std::getline(stream, line))
        {
            execute(line);
        }
    }

private:
    std::unordered_map<std::string, int> variables;

    void execute(const std::string &line)
    {
        std::istringstream stream(line);
        std::string command;
        stream >> command;

        if (command == "print")
        {
            std::string var;
            stream >> var;
            std::cout << variables[var] << std::endl;
        }
        else if (command == "let")
        {
            std::string var;
            int value;
            stream >> var >> value;
            variables[var] = value;
        }
        else if (command == "add")
        {
            std::string var1, var2, var3;
            stream >> var1 >> var2 >> var3;
            variables[var1] = variables[var2] + variables[var3];
        }
        // Agrega más comandos según sea necesario
    }
};

void runFile(const std::string &filename)
{
    if (filename.substr(filename.find_last_of(".") + 1) != "rdev")
    {
        std::cerr << "Error: El archivo debe tener la extensión .rdev" << std::endl;
        return;
    }

    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: No se pudo abrir el archivo " << filename << std::endl;
        return;
    }

    std::string code((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    Interpreter interpreter;
    interpreter.run(code);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Uso: " << argv[0] << " <archivo.rdev>" << std::endl;
        return 1;
    }

    runFile(argv[1]);
    return 0;
}







*/

// V 0.0.1 (Add commentary)

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

class Interpreter
{
public:
    void run(const std::string &code)
    {
        std::istringstream stream(code);
        std::string line;
        while (std::getline(stream, line))
        {
            // Ignorar líneas de comentarios
            if (line.empty() || line[0] == '#')
            {
                continue;
            }
            execute(line);
        }
    }

private:
    std::unordered_map<std::string, int> variables;

    void execute(const std::string &line)
    {
        std::istringstream stream(line);
        std::string command;
        stream >> command;

        if (command == "print")
        {
            std::string var;
            stream >> var;
            std::cout << variables[var] << std::endl;
        }
        else if (command == "let")
        {
            std::string var;
            int value;
            stream >> var >> value;
            variables[var] = value;
        }
        else if (command == "add")
        {
            std::string var1, var2, var3;
            stream >> var1 >> var2 >> var3;
            variables[var1] = variables[var2] + variables[var3];
        }
        // Agrega más comandos según sea necesario
    }
};

void runFile(const std::string &filename)
{
    if (filename.substr(filename.find_last_of(".") + 1) != "rdev")
    {
        std::cerr << "Error: El archivo debe tener la extensión .rdev" << std::endl;
        return;
    }

    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: No se pudo abrir el archivo " << filename << std::endl;
        return;
    }

    std::string code((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    Interpreter interpreter;
    interpreter.run(code);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Uso: " << argv[0] << " <archivo.rdev>" << std::endl;
        return 1;
    }

    runFile(argv[1]);
    return 0;
}
