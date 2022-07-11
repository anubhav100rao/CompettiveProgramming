#include "template.cpp"

class Matrix {
      public:
        Matrix(int, int);
        Matrix(const Matrix &);
        Matrix &operator=(const Matrix &);
        ~Matrix();

        inline ll &operator()(int x, int y) { return p[x][y]; }
        inline ll *&operator[](int x) { return p[x]; }

        Matrix &operator+=(const Matrix &);
        Matrix &operator-=(const Matrix &);
        Matrix &operator*=(const Matrix &);
        Matrix &operator*=(ll);
        Matrix &operator/=(ll);
        Matrix operator^(int);

        friend std::ostream &operator<<(std::ostream &, const Matrix &);
        friend std::istream &operator>>(std::istream &, Matrix &);

        void swapRows(int, int);
        Matrix transpose();

        static Matrix createIdentity(int);

        // functions on vectors
        static ll dotProduct(Matrix, Matrix);

      private:
        int rows_, cols_;
        ll **p;

        void allocSpace();
        Matrix expHelper(const Matrix &, int);
};

Matrix operator+(const Matrix &, const Matrix &);
Matrix operator-(const Matrix &, const Matrix &);
Matrix operator*(const Matrix &, const Matrix &);
Matrix operator*(const Matrix &, ll);
Matrix operator*(ll, const Matrix &);
Matrix operator/(const Matrix &, ll);

Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
        allocSpace();
        for (int i = 0; i < rows_; ++i) {
                for (int j = 0; j < cols_; ++j) {
                        p[i][j] = 0;
                }
        }
}

Matrix::~Matrix() {
        for (int i = 0; i < rows_; ++i) {
                delete[] p[i];
        }
        delete[] p;
}

Matrix::Matrix(const Matrix &m) : rows_(m.rows_), cols_(m.cols_) {
        allocSpace();
        for (int i = 0; i < rows_; ++i) {
                for (int j = 0; j < cols_; ++j) {
                        p[i][j] = m.p[i][j];
                }
        }
}

Matrix &Matrix::operator=(const Matrix &m) {
        if (this == &m) {
                return *this;
        }

        if (rows_ != m.rows_ || cols_ != m.cols_) {
                for (int i = 0; i < rows_; ++i) {
                        delete[] p[i];
                }
                delete[] p;

                rows_ = m.rows_;
                cols_ = m.cols_;
                allocSpace();
        }

        for (int i = 0; i < rows_; ++i) {
                for (int j = 0; j < cols_; ++j) {
                        p[i][j] = m.p[i][j];
                }
        }
        return *this;
}

Matrix &Matrix::operator+=(const Matrix &m) {
        for (int i = 0; i < rows_; ++i) {
                for (int j = 0; j < cols_; ++j) {
                        p[i][j] += m.p[i][j];
                }
        }
        return *this;
}

Matrix &Matrix::operator-=(const Matrix &m) {
        for (int i = 0; i < rows_; ++i) {
                for (int j = 0; j < cols_; ++j) {
                        p[i][j] -= m.p[i][j];
                }
        }
        return *this;
}

Matrix &Matrix::operator*=(const Matrix &m) {
        Matrix temp(rows_, m.cols_);
        for (int i = 0; i < temp.rows_; ++i) {
                for (int j = 0; j < temp.cols_; ++j) {
                        for (int k = 0; k < cols_; ++k) {
                                temp.p[i][j] += (p[i][k] * m.p[k][j]);
                        }
                }
        }
        return (*this = temp);
}

Matrix &Matrix::operator*=(ll num) {
        for (int i = 0; i < rows_; ++i) {
                for (int j = 0; j < cols_; ++j) {
                        p[i][j] *= num;
                }
        }
        return *this;
}

Matrix &Matrix::operator/=(ll num) {
        for (int i = 0; i < rows_; ++i) {
                for (int j = 0; j < cols_; ++j) {
                        p[i][j] /= num;
                }
        }
        return *this;
}

Matrix Matrix::operator^(int num) {
        Matrix temp(*this);
        return expHelper(temp, num);
}

void Matrix::swapRows(int r1, int r2) {
        ll *temp = p[r1];
        p[r1] = p[r2];
        p[r2] = temp;
}

Matrix Matrix::transpose() {
        Matrix ret(cols_, rows_);
        for (int i = 0; i < rows_; ++i) {
                for (int j = 0; j < cols_; ++j) {
                        ret.p[j][i] = p[i][j];
                }
        }
        return ret;
}

/* STATIC CLASS FUNCTIONS
 ********************************/

Matrix Matrix::createIdentity(int size) {
        Matrix temp(size, size);
        for (int i = 0; i < temp.rows_; ++i) {
                for (int j = 0; j < temp.cols_; ++j) {
                        if (i == j) {
                                temp.p[i][j] = 1;
                        } else {
                                temp.p[i][j] = 0;
                        }
                }
        }
        return temp;
}

// functions on VECTORS
ll Matrix::dotProduct(Matrix a, Matrix b) {
        ll sum = 0;
        for (int i = 0; i < a.rows_; ++i) {
                sum += (a(i, 0) * b(i, 0));
        }
        return sum;
}

void Matrix::allocSpace() {
        p = new ll *[rows_];
        for (int i = 0; i < rows_; ++i) {
                p[i] = new ll[cols_];
        }
}

Matrix Matrix::expHelper(const Matrix &m, int num) {
        if (num == 0) {
                return createIdentity(m.rows_);
        } else if (num == 1) {
                return m;
        } else if (num % 2 == 0) { // num is even
                return expHelper(m * m, num / 2);
        } else { // num is odd
                return m * expHelper(m * m, (num - 1) / 2);
        }
}

Matrix operator+(const Matrix &m1, const Matrix &m2) {
        Matrix temp(m1);
        return (temp += m2);
}

Matrix operator-(const Matrix &m1, const Matrix &m2) {
        Matrix temp(m1);
        return (temp -= m2);
}

Matrix operator*(const Matrix &m1, const Matrix &m2) {
        Matrix temp(m1);
        return (temp *= m2);
}

Matrix operator*(const Matrix &m, ll num) {
        Matrix temp(m);
        return (temp *= num);
}

Matrix operator*(ll num, const Matrix &m) { return (m * num); }

Matrix operator/(const Matrix &m, ll num) {
        Matrix temp(m);
        return (temp /= num);
}

ostream &operator<<(ostream &os, const Matrix &m) {
        for (int i = 0; i < m.rows_; ++i) {
                os << m.p[i][0];
                for (int j = 1; j < m.cols_; ++j) {
                        os << " " << m.p[i][j];
                }
                os << endl;
        }
        return os;
}

istream &operator>>(istream &is, Matrix &m) {
        for (int i = 0; i < m.rows_; ++i) {
                for (int j = 0; j < m.cols_; ++j) {
                        is >> m.p[i][j];
                }
        }
        return is;
}
