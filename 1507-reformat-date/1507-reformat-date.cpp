class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> m{{"Jan", "01"},
                                        {"Feb", "02"},
                                        {"Mar", "03"},
                                        {"Apr", "04"},
                                        {"May", "05"},
                                        {"Jun", "06"},
                                        {"Jul", "07"},
                                        {"Aug", "08"},
                                        {"Sep", "09"},
                                        {"Oct", "10"},
                                        {"Nov", "11"},
                                        {"Dec", "12"}};
        string year,month,day="";
        istringstream is(date);
        is>>day>>month>>year;
        day=day.substr(0,day.length()-2);
        if(day.size()<=1) day="0"+day;
        date=year+"-"+m[month]+"-"+day;
        return date;
    }
};