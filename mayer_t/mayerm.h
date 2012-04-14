#ifndef MAYER_MACRO_HEADER
#define MAYER_MACRO_HEADER

#include <iostream>
#include <vector>
#include <fstream>

#define NULL_STRING_MEDKEY ""

typedef enum {
  match='+', sub='-',      
} keys_t;

typedef keys_t keys;

class mayer_t {
        
      double a;      /* not precise */
      
      public:
             std::vector<std::string> retrieve(const char *file);
             std::vector<double> x, y;    
             inline void activate(const char*, std::vector<double>&, std::vector<double>&);                                      
             inline void add(std::string&);
             void table();
             void calculate();
             std::string usage(void);
             std::string usage(std::string&);
      private:             
             int occur (std::string, char);
             void parse(std::vector<double>&, std::vector<double>&, std::string);
             void initialize();  
             static bool initialized;
             inline bool size_check();             
             float average_t(std::vector<double>);
             float average_t(double d[]);
             void dispose();
};

#endif
