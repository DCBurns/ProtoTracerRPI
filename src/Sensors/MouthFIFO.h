

class MouthFIFO {
private:
    float MaxMouthInd = 4.0f;
    
    std::ifstream fifo;

    uint8_t currentInd = 0;

    const char *fifoname = "/tmp/mouthfifo";

    void getLatest() {

    }

    int openFIFO() {
        // fd = open(fifo, O_RDONLY|O_NONBLOCK);
        fifo.open(fifoname, std::ios_base::in);

        if(!fifo.is_open()){
            printf("FIFO: open() failed\n");
            return 0;
        }

        printf("FIFO open!");

        return 1;
    }

    uint8_t readLatest() {
        if(!fifo.is_open()) {
            printf("FIFO not open but reading??");

            openFIFO();
            return 0;
        }
        
        auto available = fifo.rdbuf()->in_avail();
        printf("Available: %d\n", available);

        for(int i = 0; i < available; i++) {
            currentInd = (uint8_t) fifo.get();
        }
        printf("Mouth: %d", currentInd);
        //fifo.read((char*)currentValue, menuCount);

    }

public:

    MouthFIFO() {
        openFIFO();
    }

    float getScale() {
        readLatest();

        return currentInd / MaxMouthInd;
    }

};