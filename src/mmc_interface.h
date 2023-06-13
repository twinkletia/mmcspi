declare mmc_interface
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
