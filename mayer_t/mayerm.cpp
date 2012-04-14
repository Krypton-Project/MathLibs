#include <iostream>
#include "mayerm.h"

int flines(const char *file);

void mayer_t::table()
{
     std::cout << "X\t|\tY\n" << "================="
     << std::endl;
     for (int index = 0; index < x.size(); index++)
         std::cout << x[index] << "\t|\t" << y[index]
         << std::endl;         
}

std::vector<std::string> mayer_t::retrieve(const char *file)
{
    std::ifstream f;
    f.open(file);
    int pos = 0;
    std::string holder;
    std::vector<std::string> data;
    
    while (f.good())
    {
         getline(f, holder);  
         if (holder.find(",", 0) == (-1) || occur(holder, ',') != 1)
            break;         
         else 
              data.push_back(holder);
    }
    f.close();    
    return data;
}

int mayer_t::occur(std::string s, char token)
{
    int count = 0;
    for (int buff = 0; buff < s.size(); buff++)
        if (s[buff] == token)
           ++count; 
    return count;  
}

inline void mayer_t::add(std::string &type) { parse(x, y, type); };        /* IMPORTANT! MAIN ENTRY POINT! */

void mayer_t::parse(std::vector<double> &point, std::vector<double> &target, std::string data)
{
    std::string one = "", two = "";
    try {
    for (int i = 0; i < data.size(); i++)
        if (data[i] != ',' && data[i] != ' ')
           one+=data[i];
        else
           break; 
    } catch (...) { std::cout << "error: code fatal (-1)." << std::endl; };
    
    try {
    for (int i = (data.find(",") + 1); i < data.size(); i++)
        if (data[i] != ',' && data[i] != ' ')
           two+=data[i];
        else
           break; 
    } catch (...) { std::cout << "error: code fatal (-1)." << std::endl; };
        
    point.push_back((double)atof(one.c_str()));
    target.push_back((double)atof(two.c_str()));
}

int flines(const char *file)
{
    int lines = 0;
    std::ifstream f;
    std::string ln;
    f.open(file);
    while (f.good()) {
          getline(f, ln);
          lines++;
    }
    f.close();
    return lines;
}

inline bool mayer_t::size_check()
{
   if (x.size() != y.size())
      return false;
   else
      return true;       
}
void mayer_t::initialize() { x[0] = 0; y[0] = 0; };
void mayer_t::dispose() { free(this); };
float mayer_t::average_t(std::vector<double> v)
{
    double sum = 0.0;
    int count = v.size();    
    for (int i = 0; i < v.size(); i++)
        sum += v[i];
    
    return (sum / count);
}

float mayer_t::average_t(double d[])
{
    size_t sz = sizeof d; 
    float f = 0.0;
    for (int i = 0; i < sizeof(d); i++)
        f+=d[i];
    return (f / sz);
}

void mayer_t::calculate()
{
    if (size_check())      /* Perfect */
    {
        std::vector<double> xlist, ylist, _xlist, _ylist;                   
        for (int i = 0; i < ((int)(x.size() / 2)); i++)
        {
            xlist.push_back(x[i]);
            ylist.push_back(y[i]);     
        }                    
        
        for (int i = ((int)(x.size() / 2)); i < x.size(); i++)        
        {
            _xlist.push_back(x[i]);
            _ylist.push_back(y[i]);     
        }
        
        try {
       
            double x1 = average_t(xlist), y1 = average_t(ylist);
            double x2 = average_t(_xlist), y2 = average_t(_ylist);        
            double a = ((y2 - y1) / (x2 - x1));
            std::cout << "a\t=\t" << a << std::endl;
        }
        catch (...) { std::cout << "error: code fatal (-1)." << std::endl; };
    }
}
