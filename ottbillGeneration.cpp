class BillGeneration{
    int netflix;
    int amazon;
    int hotstar;
};
class StreamService{
    public:
    virtual int getTotalCost()= 0;
    virtual int getTotalHours() = 0;
};

class Netflix : public StreamService{
    private:
    int unitCost = 10;
    int unitHours = 10;

    int getTotalCost(int hours) override{
        if(hours%unitHours!=0){
            cout<<"Watching hours should be in multiple of"<<unitHours<<endl;
            return -1;
        }
        return (hours/unitHours)*unitCost;  
    }

    int getTotalHours() override{
        return unitHours;
    }
};

class Hotstar : public StreamService{
    private:
    int unitCost = 1;
    int unitHours = 2;

    int getTotalCost(int hours) override{
        if(hours%unitHours!=0){
            cout<<"Watching hours should be in multiple of"<<unitHours<<endl;
            return -1;
        }
        return (hours/unitHours)*unitCost;  
    }

    int getTotalHours() override{
        return unitHours;
    }
};

class Amazon : public StreamService{
    private:
    int unitCost = 2;
    int unitHours = 5;

    int getTotalCost(int hours) override{
        if(hours%unitHours!=0){
            cout<<"Watching hours should be in multiple of"<<unitHours<<endl;
            return -1;
        }
        return (hours/unitHours)*unitCost;  
    }

    int getTotalHours() override{
        return unitHours;
    }
};

class OttBillCalculator{
    unordered_map<string, StreamService*>services;

    public:

    OttBillCalculator(){
        services["Netflix"] = new Netflix();
        services["Amazon"] = new Amazon();
        services["Hotstar"] = new Hotstar();
    }
    int totalCost(unordered_map<string, int>ottservice){
        int totalCostToPay
        for(const auto &[service, hours] : ottservice){
            if(services.find(service)!= services.end()){
                totalCostToPay += services[service]->getTotalCost(hours);
            }
        }
        return totalCostToPay;
    }

};