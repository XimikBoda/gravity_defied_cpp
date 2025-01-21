#pragma once

#include <fstream>
#include <algorithm>
#include <filesystem>

class FileStream {
public:
    FileStream()
    {
    }

    FileStream(const std::filesystem::path& file, std::ios::openmode mode)
    {
        stream.open(file, mode);
    }

    ~FileStream()
    {
        stream.close();
    }

    template <class T>
    void readVariable(T* p, bool swapEndianness = false, std::size_t size = 0)
    {
        char* pChar = reinterpret_cast<char*>(p);
        if (!size) {
            size = sizeof(T);
        }
        read_impl(pChar, size);
        if (swapEndianness) {
            std::reverse(pChar, pChar + size);
        }
    }

    template <class T>
    void writeVariable(T* p, std::size_t size = 0)
    {
        char* pChar = reinterpret_cast<char*>(p);
        if (!size) {
            size = sizeof(T);
        }
        write_impl(pChar, size);
    }

    virtual bool isOpen()
    {
        return stream.is_open();
    }

    virtual void setPos(std::streampos pos)
    {
        stream.seekg(pos);
    }

private:
    std::fstream stream;

    virtual void read_impl(char* s, std::streamsize n)
    {
        stream.read(s, n);
    }

    virtual void write_impl(char* s, std::streamsize n)
    {
        stream.write(s, n);
    }
};
