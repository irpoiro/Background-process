#include <iostream>
#include <Windows.h>
#include <fstream>
#include <tlhelp32.h>


bool IsProcessRun(const char* const processName)
{
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);
    Process32First(hSnapshot, &pe);

    while (true) {
        if (strcmp(pe.szExeFile, processName) == 0) return true;
        if (!Process32Next(hSnapshot, &pe)) return false;
    }
}
int main() {

    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);

    while (true) {
        if (IsProcessRun("processname.exe")) //ur processname.exe
        {
        //ur action

            //exit(-1);
        }
                 }
}