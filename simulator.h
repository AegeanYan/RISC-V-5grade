//
// Created by 罗皓天 on 2021/6/28.
//

#ifndef RISC_V_SIMULATOR_SIMULATOR_H
#define RISC_V_SIMULATOR_SIMULATOR_H

#include <iostream>
#include "Memory.h"
#include "ALU.h"
#include "Registor.h"
class simulator {
private:
    Registor registor;
    ALU alu;
    Memory RAM;
    int pc;
    bool end;
    struct EX_Result{
    public:
        int rd;
        int imme;
        int branch;
        int pc;
        int opt;
        EX_Result() = default;
    };
    struct MEM_Data{
    public:
        int opt;
        int rd;
        int imme;
        int branch;
        int pc;
        MEM_Data() = default;
    };
    EX_Result ex_result{};
    MEM_Data mem_data{};
public:
    simulator() {
        pc = 0;
        end = false;
    }
    void read();
    void IF();
    void ID();
    void EX(int option);
    void MEM(int option);
    void WB(int option);
    void run();
    void IF_ID();
    void ID_EX();
    void EX_MEM();
    void MEM_WB();
    void Hazard_detect();
    static int sext(const int &im ,const int &maxw);
};


#endif //RISC_V_SIMULATOR_SIMULATOR_H
