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
}
