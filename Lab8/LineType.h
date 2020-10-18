class lineType {
 public:
  friend std::ostream & operator << (std::ostream &out, const lineType &otherLine);
  friend std::istream & operator >> (std::istream &in, lineType &otherLine);
  void operator=(const lineType &line);
  void setLine(double a = 0, double b = 0, double c = 0);
  // Function to set the line.

  void equation() const;

  double getXCoefficient() const;
  double getYCoefficient() const;
  double getCOnstantTerm() const;

  void setXCoefficient(double coeff);
  void setYCoefficient(double coeff);
  void setConstantTerm(double c);

  double slope() const;
  // Return the slope. This function does not check if the
  // line is vartical. Because the slope of a vertical line
  // is undefined, before calling this function check if the
  // line is nonvertial.

  bool operator+();
  bool verticalLine() const;
  bool operator-();
  bool horizontalLine() const;

  bool operator==(const lineType &otherLine);
  bool equalLines(lineType otherLine) const;
  // Returns true of both lines are the same.

  bool operator||(lineType otherLine);
  bool parallel(lineType otherLine) const;
  // Function to determine if this line is parallel to otherLine.

  bool operator&&(lineType otherLine);
  bool perpendicular(lineType otherLine) const;
  // Function to determine if this line is perperdicular to otherLine.

  void pointOfIntersection(lineType otherLine);
  // If lines intersect, then this function finds the point
  // of intersection.

  lineType(double a = 0, double b = 0, double c = 0);
  // Constructor

 private:
  double xCoeff;
  double yCoeff;
  double constTerm;
  bool hasSlope;
};