#include <iostream>
#include <vector>


namespace patterns {

    class Worker {
    public:
        int state;

    };

    class Pool {
    private:
        std::vector<Worker*> occupiedWorkers;
        std::vector<Worker*> freeWorkers;

    static void clearWorker(Worker* unclearWorker) {
        unclearWorker->state = 0;
    }

    public:
        Worker* getWorker() {
            Worker *lastWorker;
            if (this->freeWorkers.empty()) {
                lastWorker = new Worker();
            } else {
                lastWorker = this->freeWorkers.back();
                freeWorkers.pop_back();
            }
            this->occupiedWorkers.push_back(lastWorker);
            return lastWorker;
        }

        void returnWorker(Worker* worker) {
            for (auto occupiedWorker = this->occupiedWorkers.begin(); occupiedWorker != this->occupiedWorkers.end(); ++occupiedWorker) {
                if (worker == *occupiedWorker) {
                    this->occupiedWorkers.erase(occupiedWorker);
                    freeWorkers.push_back(worker);
                    clearWorker(worker);
                    break;
                }
            }
        }

        int freeWorkersCount() {
            return freeWorkers.size();
        }

        int occupiedWorkersCount() {
            return occupiedWorkers.size();
        }
    };


    void test_pool() {
        std::cout << "Start pool\n";
        Pool workersPool = Pool();
        Worker *worker1 = workersPool.getWorker();
        Worker *worker2 = workersPool.getWorker();
        std::cout << "count occupied workers: " << workersPool.occupiedWorkersCount() << std::endl;
        std::cout << "count free workers: " << workersPool.freeWorkersCount() << std::endl;
        worker1->state = 300;
        workersPool.returnWorker(worker1);
        workersPool.returnWorker(worker2);
        std::cout << "count occupied workers: " << workersPool.occupiedWorkersCount() << std::endl;
        std::cout << "count free workers: " << workersPool.freeWorkersCount() << std::endl;
        std::cout << "End pool\n";
    }
}
