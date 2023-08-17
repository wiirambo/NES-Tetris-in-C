# NES Tetris Recreation in C

This is a modidfied Version of the olcNES emulator, with to goal to recreate 
NES Tetris in C code. 

As this tries to recreate Tetris, the emulator only works with tetris.
Some ROM hacks of Tetris may work. The seven digit ROM hack is supported,
but the modification has to be set to SEVENDIGITS.
When creating a emulator instance some variable can be set:
emulation speed: speeds up the emulation, values greater than one currently disable vsync.
It will run at the maximum possible speed.
play movie: replays a FCEUX movie file
record movie: records the inputs into a FCEUX movie file. File has to exist and will be overwritten without warning
output audio: toggles the emulation of the apu
useCCode: toggles the usage of the C code 
id: currently unused always 0. Running multiple instances at the same time is not yet possible.


The mirrormode is hard coded to one screen mode, which Tetris uses.

Using a game genie code will only set the value at the address once. 
Other behavoir is not implemented. If the C code is used cheat codes,
which change the game code have to be implemented in order to work properly.

As this is still an early version there will be a lot of code cleanup in the future.


Because this is based on the olcNES emulator the same license applies.

# License (OLC-3)
Copyright 2018, 2019, 2020, 2021 OneLoneCoder.com

Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions 
are met:

1. Redistributions or derivations of source code must retain the above 
   copyright notice, this list of conditions and the following disclaimer.

2. Redistributions or derivative works in binary form must reproduce 
   the above copyright notice. This list of conditions and the following 
   disclaimer must be reproduced in the documentation and/or other 
   materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its 
   contributors may be used to endorse or promote products derived 
   from this software without specific prior written permission.
    
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
