#include <iostream>

//多态例子

class CPU{

public :

    virtual ~CPU(){

    }
    virtual void calculator() = 0;
};

class GPU{

public :
    
    virtual ~GPU(){

    }
    virtual void display() = 0;
};

class Memory{

public : 

    virtual ~Memory(){

    }
    virtual void loading() = 0;
};

class Computer{

public :
    
    Computer(CPU* cpu, GPU* gpu, Memory* memory){

        this->cpu = cpu;
        this->gpu = gpu;
        this->memory = memory;
    }
    ~Computer(){

        if(cpu != nullptr){

            delete cpu;
            cpu = nullptr;
        }
        if(gpu != nullptr){

            delete gpu;
            gpu = nullptr;
        }
        if(memory != nullptr){

            delete memory;
            memory = nullptr;
        }
    }
    CPU* cpu;
    GPU* gpu;
    Memory* memory;

    void work(){

        cpu->calculator();
        gpu->display();
        memory->loading();
    }
};

class IntelCPU : public CPU{

public :

    void calculator(){

        std::cout << "Intel CPU calculator" << std::endl;
    }
};

class IntelGPU : public GPU{

public :

    void display(){

        std::cout << "Inter GPU display" << std::endl;
    }
};

class IntelMemory : public Memory{

public :

    void loading(){

        std::cout << "Inter memory loading" << std::endl;
    }
};
class AmdCPU : public CPU{

public :

    void calculator(){

        std::cout << "Amd CPU calculator" << std::endl;
    }
};

class AmdGPU : public GPU{

public :

    void display(){

        std::cout << "Amd GPU display" << std::endl;
    }
};

class AmdMemory : public Memory{

public :

    void loading(){

        std::cout << "Amd memory loading" << std::endl;
    }
};

void test1(){

    //组装Intel电脑
    std::cout << "组装Intel电脑" << std::endl;
    CPU* intelCpu = new IntelCPU;
    GPU* intelGpu = new IntelGPU;
    Memory* interMemory = new IntelMemory;

    Computer* computer1 = new Computer(intelCpu,intelGpu,interMemory);
    computer1->work();
    std::cout << std::endl;

    delete computer1;
}

void test2(){

    //组装AMD电脑
    std::cout << "组装AMD电脑" << std::endl;
    CPU* amdCpu = new AmdCPU;
    GPU* amdGpu = new AmdGPU;
    Memory* amdMemory = new AmdMemory;

    Computer* computer2 = new Computer(amdCpu,amdGpu,amdMemory);
    computer2->work();
    std::cout << std::endl;

    delete computer2;

    //组装混合电脑
    std::cout << "组装混合电脑" << std::endl;
    CPU* intelCpu = new IntelCPU;
    GPU* intelGpu = new IntelGPU;
    amdMemory = new AmdMemory;

    Computer* computer3 = new Computer(intelCpu,intelGpu,amdMemory);
    computer3->work();

    delete computer3;
}

int main(){

    test1();
    test2();
    return 0;
}