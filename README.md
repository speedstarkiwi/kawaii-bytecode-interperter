# kawaii-bytecode-interperter

`kawaii bytecode interperter` is written in lua and both c++, it allows to call a function from the `init` script but will only run `lua bytecode` format. for you lua `nerdies` out there, `_G` is used to run it.

`lua bytecocde interperters` refered to **LBI** hit it's highest peak in the mid months of 2021, almost all exploits using it, sadly, it **died**.

this `repo` is `aimed` to revive becuz if you dont KNOW me i technically revive exploits from 2016 like lua c parsing, or command hacks! anyways enjoy!

# not updated

none of these addresses are updated, and some are too advanced for you 0 braincell niggas 💀

if you fail to find an address then use at least 1 brain cell to figure it out or **GET SOME HELP**

side note: `luau` (the whole fucking folder) needs to be updated every week unless you have a big brain and know how to use `__inline` which i doubt you do.
# usage

update as said above.

compile in `release x86`.

file compiled in 'Release\' directory.

# tutorial

first, update your addresses! thats like the **main** thing to do!

secondly, rename the strings! if your gonna skid, at least make it less obvious.

lastly, compile up and execute! (note: we dont use pipes but u can add it not hard)

# credits

**deadlocust** - started trend / some base help

**speedstarskiwi** - rest of code / reviving old shit

**nezyghoul** - task scheduler scanning / luau files

# IMPORTANT!

The interperter part is **BROKEN** because of the lack of time. This is because the VM is being feed the bytecode in a `wrong` way. I didnt fix it for 2 reasons: 1) Not a good idea to fix everything for a free source 2) I tried my best and it just wont feed the right way also a lack of time.

I know a **LOT** of people will skip this saying *oh no the Lua C functions wont work*, because `inline` is a shit task i dont prefer using, we use the `lua_State` as the `uintptr_t` state.

People dont know how to update it so I suggest using `__inline` and if you dont know where just type *Roblox Inlined Functions* on google and just paste em. Dont ask me for inline help.
