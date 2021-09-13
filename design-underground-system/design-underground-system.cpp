class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        inmap[id]=make_pair(stationName,t);
    }
    
    void checkOut(int id, string stationName, int t) {
        outmap[inmap[id].first][stationName].first+=t-inmap[id].second;
        outmap[inmap[id].first][stationName].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        double ave=(double)outmap[startStation][endStation].first/(double)outmap[startStation][endStation].second;
        return ave;
    }
private:
    unordered_map<int,pair<string,int>> inmap;
    unordered_map<string,unordered_map<string,pair<int,int>>> outmap; //instationname--outstationname-这个人进出站的时间差-numofpeople
    
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */