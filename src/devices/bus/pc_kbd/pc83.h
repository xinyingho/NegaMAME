// license:BSD-3-Clause
// copyright-holders:Curt Coder
/**********************************************************************

    IBM 5150 83-key keyboard emulation

*********************************************************************/

#ifndef MAME_BUS_PC_KBD_PC83_H
#define MAME_BUS_PC_KBD_PC83_H

#pragma once

#include "cpu/mcs48/mcs48.h"
#include "pc_kbdc.h"
#include "machine/rescap.h"



//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

// ======================> ibm_pc_83_keyboard_device

class ibm_pc_83_keyboard_device :  public device_t,
									public device_pc_kbd_interface
{
public:
	// construction/destruction
	ibm_pc_83_keyboard_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

protected:
	// device-level overrides
	virtual void device_start() override ATTR_COLD;
	virtual void device_reset() override ATTR_COLD;

	// optional information overrides
	virtual const tiny_rom_entry *device_rom_region() const override ATTR_COLD;
	virtual void device_add_mconfig(machine_config &config) override ATTR_COLD;
	virtual ioport_constructor device_input_ports() const override ATTR_COLD;

	// device_pc_kbd_interface overrides
	virtual void clock_write(int state) override { }
	virtual void data_write(int state) override { }

private:
	void bus_w(uint8_t data);
	uint8_t p1_r();
	void p2_w(uint8_t data);
	int t0_r();

	required_device<i8048_device> m_maincpu;
	required_ioport_array<24> m_dr;

	uint8_t m_cnt;
};


// device type definition
DECLARE_DEVICE_TYPE(PC_KBD_IBM_PC_83, ibm_pc_83_keyboard_device)


#endif // MAME_BUS_PC_KBD_PC83_H
