// GB Enhanced+ Copyright Daniel Baxter 2014
// Licensed under the GPLv2
// See LICENSE.txt for full license text

// File : core.h
// Date : September 14, 2015
// Description : Emulator core
//
// The "Core" is an abstraction for all of emulated components
// It controls the large-scale behavior of the CPU, LCD/GPU, MMU, and APU/DSP
// Can start, stop, and reset emulator
// Also contains a debugging unit


#ifndef NDS_CORE
#define NDS_CORE

#include "common/core_emu.h"
#include "common/config.h"
#include "mmu.h"
#include "lcd.h"
#include "arm9.h"

class NTR_core : virtual public core_emu
{
	public:
		NTR_core();
		~NTR_core();

		//Core control
		void start();
		void stop();
		void reset();
		void shutdown();
		void handle_hotkey(SDL_Event& event);
		void update_volume(u8 volume);
		void feed_key_input(int sdl_key, bool pressed);
		void run_core();

		//Core debugging
		void debug_step();
		void debug_display() const;
		void debug_process_command();

		//CGFX interface
		void dump_obj(int obj_index);
		void dump_bg(int bg_index);
		u32* get_obj_palette(int pal_index);
		u32* get_bg_palette(int pal_index);

		//MMU related functions
		bool read_file(std::string filename);
		bool read_bios(std::string filename);
		u8 ex_read_u8(u16 address);
		void ex_write_u8(u16 address, u8 value);

		NTR_MMU core_mmu;
		ARM9 core_cpu_nds9;
		
		/*
		ARM7 core_cpu;
		NDS_GamePad core_pad;
		*/
};
		
#endif // NDS_CORE
