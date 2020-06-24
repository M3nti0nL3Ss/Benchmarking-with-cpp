#include<iostream>
#include<chrono>

class Timer {
public:
    Timer(){
        startPoint = std::chrono::high_resolution_clock::now();
    }
    
    void Stop(){
        auto stopPoint = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startPoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(stopPoint).time_since_epoch().count();
        auto duration = end - start;
        double microseconds = duration * .001;
        std::cout << microseconds << " ms\n";
    }
    
    ~Timer(){
        Stop();
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startPoint;
};


int main(){
    int i=0,value=0;
    {
        Timer timer;
        for(;i<100000000;i++)
            value+=2;
    }
}
