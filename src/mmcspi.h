#ifndef MMCSPI_H
#define MMCSPI_H

#define HIGH 1'b1
#define LOW 1'b0
#define HI_Z 1'bz

declare mmcspi
{
    output CS;
    input MISO;
    output MOSI;
    output SCLK;

    func_in reset();
    input read_adrs[12];
    input write_adrs[12];
    input byteen[3];
    output rdata[32];
    input wdata[32];
    func_in read(read_adrs, byteen);
    func_in write(write_adrs, byteen, wdata);
    func_out valid();
    func_out load_access_fault();
    func_out store_amo_access_fault();
    func_out interrupt_req();
#ifdef DEBUG
    output debugstatus[32];
    func_out debug_status(debugstatus);
#endif
#ifdef CV
    input SW[10];
    output pc_led[10];
    func_out debug_pc_led(pc_led);
    output sseg_h8[8];
    func_out debug_sseg_h8(sseg_h8);
    output sseg_l16[16];
    func_out debug_sseg_l16(sseg_l16);
    output sseg_l12[12];
    func_out debug_sseg_l12(sseg_l12);
    output sseg_h12[12];
    func_out debug_sseg_h12(sseg_h12);
    func_out debug_led_1();
    func_out debug_led_2();
    func_out debug_led_3();
    func_out debug_led_4();
    func_out debug_led_5();
    func_out debug_led_6();
    func_out debug_led_7();
    func_out debug_led_8();
    func_out debug_led_9();
    func_out debug_led_10();
#endif
}

struct command_token_t
{
    command[8];
    arguments[32];
    crc[8];
};
struct response_1_t
{
    start_bit[1];   
    parameter_error[1];
    address_error[1];
    erase_sequence_error[1];
    communication_crc_error[1];
    illegal_command[1];
    erase_reset[1];
    in_idle_state[1];
};

struct respose_2_t{
    start_bit[1];   //0
    parameter_error[1];
    address_error[1];
    erase_sequence_error[1];
    communication_crc_error[1];
    illegal_command[1];
    erase_reset[1];
    in_idle_state[1];
    out_of_range[1];    //0
    erase_param[1];
    wp_violation[1];
    card_ecc_failed[1];
    cc_error[1];
    error[1];
    wes_or_lucf[1]; //wp erase skip or lock/unlock cmd failed
    card_is_locked[1];
}

struct status_t
{
    exec[1];
    interrupt_enable[1];
    error[1];
    idle[1];
    inited[1];
};
struct operation_t
{
    x[30];
    write[1];
    read[1];
};

#define CMD0 0x40_00_00_00_00_95
#define CMD1 0x41_00_00_00_00_f9
/* 512 byte */
#define CMD16 0x50_00_00_02_00_01
#define CMD17 0x51_00_00_00_00_01
#define CMD24 0x58_00_00_00_00_01
#endif
