#include <Windows.h>
#include <cstdio>
#include <thread>
#include <iostream>
#include <string>
#include <sstream>
#include "CallCheck.h"
#include "Addresses.h"
#include "Execution.h"


void ConsoleBypass() {//creates console internally into roblox (because its a DLL dumbass)

    VirtualProtect(FreeConsole, 1, PAGE_EXECUTE_READWRITE, new unsigned long);
    *reinterpret_cast<unsigned int*>(FreeConsole) = 0xC3;
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    freopen("CONIN$", "r", stdin);
    SetWindowPos(GetConsoleWindow(), HWND_TOPMOST, 50, 20, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
    ShowWindow(GetConsoleWindow(), 1);//1 = the window command
    SetConsoleTitleA("kawaii uwu interperter");//change to whatever
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Main()//loads this function into the thread (dont need to explain shit 4 this lmao)
{
    ConsoleBypass();
    rL = luastate(get_sc());
    printf("Got lua state!\n");
    StartExecution(true);
    printf("Interperter startup!\n");
    AddVectoredExceptionHandler(1, ccVEH);
    printf("Script execution available!\n");
    Sleep(500);
    while (true)
    {
        std::cout << " > ";
        std::string InputScript;
        std::getline(std::cin, InputScript);
        Execute(rL, InputScript);
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        std::thread(Main).detach();
        break;
    }
    return TRUE;
}

