#pragma once
#include <Windows.h>
#include <string>

int aslr(int x) { return(x - 0x400000 + reinterpret_cast<int>(GetModuleHandleA(0))); }//uses aslr onto the addresses and performing math w/ roblox base handle address
uintptr_t rL;//roblox lua state [null]

//list of addresses, and offsets (also math vars)
//update each WEEK! i knew adding an auto updater for a free source is very not a good thing to do

uintptr_t top_offset = 16, base_offset = 20;//why not (int)? because i like to point* at furries

uintptr_t getstate_addy = aslr(0x0);
uintptr_t getscheduler_addy = aslr(0x0);
uintptr_t taskdefer_addy = aslr(0x0);
uintptr_t print_addy = aslr(0x0);
uintptr_t watchdog_addy = aslr(0x0);
uintptr_t luavm_addy = aslr(0x0);

using r_getscheduler = uintptr_t(__cdecl*)();//returns the lua state
r_getscheduler lua_getscheduler = (r_getscheduler)(aslr(0xAFE9D0));

typedef uintptr_t(__thiscall* r_getstate)(uintptr_t SC, int* stateType);
r_getstate lua_getstate = reinterpret_cast<r_getstate>(aslr(0x77A360));

using r_taskdefer = uintptr_t(__cdecl*)(uintptr_t rl);//should act as spawn? not fs
r_taskdefer lua_taskdefer = (r_taskdefer)(aslr(0x7B75C0));

using r_print = uintptr_t(__cdecl*)(int type, const char* source);//prints onto dev console
r_print lua_print = (r_print)(aslr(0x1016600));

using r_luavm_load = uintptr_t(__fastcall*)(uintptr_t rl, std::string* src, const char* chnk, int env);//loads specified args to roblox
r_luavm_load luavm_load = (r_luavm_load)(aslr(0x73F760));//not deserialize in any way

uintptr_t luastate(uintptr_t sc)//actual luastate also returns in getstate as last case as well OwO
{
    return *(DWORD*)(sc + 236) - (sc + 236);
}

//[below] here is the scheduler / lua state grabber! made by https://github.com/nezyDev/ go appreciate him :)
//I SUGGEST not fucking up anything here because it works, maybe the jobs outdated can be found 'GetScheduler/GetState'

uintptr_t get_scheduler()//returns the getscheduler function
{
    return lua_getscheduler();
}

int get_job(const char* job_name)//gets job (already set) with the job offsets 
{
    auto job_return = 0;

    auto job_start = *reinterpret_cast<uintptr_t*>(get_scheduler() + 308);

    while (job_start != *(uintptr_t*)(lua_getscheduler() + 312))
    {
        if (*(std::string*)(*(uintptr_t*)(job_start)+16) == job_name)
        {
            job_return = *(uintptr_t*)(job_start);
        }
        job_start += 8;
    };

    return job_return;
}

int get_sc()
{
    return *(uintptr_t*)(get_job("WaitingHybridScriptsJob") + 304);//what type of job you wanna return with the job offsets
}

int get_lua_state()
{
    int type = 0;//why roblox made 2nd argument null lol when theres nothing XD
    return lua_getstate(get_sc(), &type);
}