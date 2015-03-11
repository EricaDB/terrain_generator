class MyClass {
public:
  MyClass(int x, std::string y)
    : x(x)
    , y(y)
  {}

  void incrementX();
  void incrementY();

  int getX() const;
  void setX(int x_);

  static std::string getStringFromInstance(const MyClass& instance);

private:
  int x;
  std::string y;
};

