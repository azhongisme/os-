#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
#include <iostream>

class BankAlgorithm {
private:
  std::string name_;
  std::vector<int64_t> max_;
  std::vector<int64_t> allocation_;
  std::vector<int64_t> need_; 
  static std::vector<int64_t> available_;
  static std::vector<int64_t> resource_;

public:
  BankAlgorithm() = delete;
  
  BankAlgorithm(const std::string name, const std::vector<int64_t> m, const std::vector<int64_t> allo)
    :  max_(m), allocation_(allo) {}
  
  ~ BankAlgorithm() = default;

  BankAlgorithm& operator = (BankAlgorithm&&) = delete; 

  void UpdateAllocaltion(const std::vector<int64_t> a);
  
  //Finish a process
  void UpdateAvailable();

  static std::vector<int64_t>& GetAvailable();

  static void SetAvailable(const std::vector<int64_t> a);

  static void SetResource(const std::vector<int64_t> a);

  static void InitAvailable(int n);

  static void InitResource(int n);

  void Print();

  static void Show(std::vector<BankAlgorithm> b);
};



#endif