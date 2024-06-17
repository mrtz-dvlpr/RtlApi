#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <rtl-sdr.h>
#include <libdvbv5/dvb-fe.h>
#include <libdvbv5/dvb-v5-std.h>
#include<iostream>

int main() {


    // // Initialize RTL-SDR
    rtlsdr_dev_t *sdr_device;
    if (rtlsdr_open(&sdr_device, 0) != 0) {
        std::cout<<__LINE__<<"  "<<stderr<<"  "<< "Failed to open RTL-SDR device\n"<<std::endl;
        return -1;
    }

    // Set the frequency to a DVB-T channel
    int frequency = 88000000; // Example frequency in Hz
    if (rtlsdr_set_center_freq(sdr_device, frequency) != 0) {
        std::cout<<__LINE__<<"  "<<stderr<<"  "<<"Failed to set center frequency\n"<<std::endl;
        rtlsdr_close(sdr_device);
        return -1;
    }


    uint32_t bandWidth=8e3;
    if(    rtlsdr_set_tuner_bandwidth(sdr_device,bandWidth) != 0){
        std::cout<<__LINE__<<"  "<<stderr<<"  "<<"Failed to set bandwidth\n"<<std::endl;
        rtlsdr_close(sdr_device);
        return -1;
    }

    uint32_t sampleRate=3.2e6;
    if(rtlsdr_set_sample_rate(sdr_device,sampleRate)!= 0){
        std::cout<<__LINE__<<"  "<<"Failed to set sample rate"<<std::endl;
        rtlsdr_close(sdr_device);
        return -1;
    }


    int rtlSdrGain=20;
    if(    rtlsdr_set_tuner_gain(sdr_device,rtlSdrGain)!=0){
        std::cout<<__LINE__<<"  "<<"faild to set gain value"<<std::endl;
        rtlsdr_close(sdr_device);
        return -1;
    }







        // // Initialize libdvbv5 DVB-T parameters
        // struct dvb_v5_fe_parms *dvb_params = dvb_fe_open(0,0,0,0);
        // if (!dvb_params) {
        //     fprintf(stderr, "Failed to open DVB frontend\n");
        //     rtlsdr_close(sdr_device);
        //     return -1;
        // }

        // dvb_fe_store_parm(dvb_params, DTV_FREQUENCY, frequency);
        // dvb_fe_store_parm(dvb_params, DTV_BANDWIDTH_HZ, 8000000);

        // if (dvb_fe_set_parms(dvb_params) != 0) {
        //     fprintf(stderr, "Failed to tune to the channel\n");
        //     dvb_fe_close(dvb_params);
        //     rtlsdr_close(sdr_device);
        //     return -1;
        // }

        // // Read samples from the device (simplified example)
        // const int buffer_size = 16384; // Size of the buffer for reading
        // samples uint8_t *buffer = (uint8_t *)malloc(buffer_size *
        // sizeof(uint8_t));

        // while (true) {
        //     int n_read;
        //     if (rtlsdr_read_sync(sdr_device, buffer, buffer_size, &n_read) !=
        //     0 || n_read != buffer_size) {
        //         fprintf(stderr, "Failed to read samples\n");
        //         break;
        //     }

        //     // Process the samples (demodulate and decode)
        //     // ...

        //     // Output the stream
        //     // ...
        // }

        // free(buffer);

        // // Clean up
        // dvb_fe_close(dvb_params);
        // rtlsdr_close(sdr_device);

        return 0;
}
