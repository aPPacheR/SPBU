#include "Header.h"

std::ostream& operator<<(std::ostream& out, const BigInteger& X) {
	if (X.sign_ == false) {
		out << '-';
	}
	for (int i = 0; i < X.size_; ++i) {
		out << X.value_[i];
	}
	return out;
}

// конструкторЫ
BigInteger::BigInteger() {
	for(int i = 0; i < 256; ++i) {
		value_[i] = 0;
		sign_ = true;
		size_ = 1;
	}
}

BigInteger::BigInteger(int X) {
	int i = 0;
	int temp[50];
	sign_ = true;
	if (X < 0) {
		sign_ = false;
		X *= (-1);
	}
	while ((X / 10 != 0) || (X < 10)) {  //разбиение на разряды
		if (X < 10) {
			temp[i] = X;
			break;
		}
		temp[i] = X % 10;
		X = (X - X % 10) / 10;
		i++;
	}
	size_ = i + 1;                  //заполнение массива
	int j = i;
	while (j > 0) {
		value_[i - j] = temp[j];
		j--;
	}
	value_[i] = temp[0];

}

BigInteger::BigInteger(const std::string& value) {
	if (value.length() == 0) {
		for (int i = 0; i < 256; ++i) {
			value_[i] = 0;
			sign_ = true;
			size_ = 1;
		}
	} else {
		if (value[0] == '-') {
			sign_ = false;
			size_ = value.length() - 1;
		} else {
			sign_ = true;
			size_ = value.length();
		}
		for (int i = 0; i < value.length(); ++i) {
			if (sign_ == true) {
				if (value[i] >= '0' && value[i] <= '9') {
					value_[i] = value[i] - '0';
				} else {
					//std::cout << "Error" << std::endl;
				}
			} else {
				if (value[i + 1] >= '0' && value[i + 1] <= '9') {
					value_[i] = value[i + 1] - '0';
				} else {
					//std::cout << "Error" << std::endl;
				}
			}
		}
		
	}
}  //TODO

// конструктор копирования
BigInteger::BigInteger(const BigInteger& X) {
	for (int i = 0; i < 256; ++i) {
		value_[i] = X.value_[i];
		sign_ = X.sign_;
		size_ = X.size_;
	}
}

// унарные плюс и минус
BigInteger BigInteger::operator-() const {
	BigInteger tmp(*this);
	tmp.sign_ = !tmp.sign_;
	return tmp;
}

BigInteger BigInteger::operator+() const {
	return BigInteger(*this);
}

// операции сравнения
bool BigInteger::operator==(const BigInteger& X){
	if(sign_ != X.sign_) {
		return false;
	} else if (size_ != X.size_) {
		return false;
	} else {
		for (int i = 0; i < size_; ++i) {
			if(value_[i] != X.value_[i]) {
				return false;
			} else {
				return true;
			}
		}
	}
}


bool BigInteger::operator!=(const BigInteger& X) {
	BigInteger tmp1 = *this;
	BigInteger tmp2 = X;
	if(tmp1 == tmp2) {
		return false;
	} else {
		return true;
	}
}

bool BigInteger::operator<(const BigInteger& X) {
	bool flag;
	if(sign_ == false && X.sign_ == true) {
		flag = true;
	} else if(sign_ == true && X.sign_ == false) {
		flag = false;
	} else if (sign_ == true && X.sign_ == true) {
		if(size_ > X.size_) {
			flag = false;
		} else if (size_ == X.size_) {
			for (int i = 0; i < X.size_; ++i) {
				if (value_[i] < X.value_[i]) {
					flag = true;
				}
				else {
					flag = false;
					break;
				}
			}
		} else {
			flag = true;
		}
	} else {
		if (size_ < X.size_) {
			flag = false;
		} else if (size_ == X.size_) {
			for (int i = 0; i < size_; ++i) {
				if (value_[i] > X.value_[i]) {
					flag = true;
				} else {
					flag = false;
					break;
				}
			}
		} else {
			flag = true;
		}
	}
	return flag;
}

bool BigInteger::operator>(const BigInteger& X) {
	BigInteger tmp1 = *this;
	BigInteger tmp2 = X;
	if(tmp1 == tmp2) {
		return false;
	} else if(tmp1 < tmp2) {
		return false;
	} else {
		return true;
	}
}

bool BigInteger::operator<=(const BigInteger& X) {
	BigInteger tmp1 = *this;
	BigInteger tmp2 = X;
	if(tmp1 > tmp2) {
		return false;
	} else {
		return true;
	}
}

bool BigInteger::operator>=(const BigInteger& X) {
	BigInteger tmp1 = *this;
	BigInteger tmp2 = X;
	if (tmp1 < tmp2) {
		return false;
	} else {
		return true;
	}
}

// операция присваивания
BigInteger& BigInteger::operator=(const BigInteger& X) {
	if(*this == X){
		return *this;
	} else {
		this->sign_ = X.sign_;
		this->size_ = X.size_;
		for (int i = 0; i < 256; ++i) {
			this->value_[i] = X.value_[i];	
		}
	}
	return *this;
}
BigInteger& BigInteger::operator=(BigInteger&& X) {
	sign_ = X.sign_;
	size_ = X.size_;
	for (int i = 0; i < 256; ++i) {
		value_[i] = X.value_[i];
	}
	return *this;
}


// арифметические операции
void BigInteger::reverse() {
	int* tmp = new int[size_];
	for (int i = 0; i < size_; ++i) {
		tmp[i] = value_[i];
	}
	int j = 0;
	for (int i = size_ - 1; i >= 0; --i) {
		value_[j] = tmp[i];
		++j;
	}
	delete[] tmp;
}

void BigInteger::deleteZero() {
	int i = size_ - 1;
	while (value_[i] == 0 && size_ != 1) {
		--size_;
		--i;
	}
}

BigInteger BigInteger::operator+(const BigInteger& X) const  {
	BigInteger tmp1;
	tmp1.sign_ = sign_;
	tmp1.size_ = size_;
	int j = 0;
	for(int i = size_ - 1; i >= 0; --i) {
		tmp1.value_[j] = value_[i];
		++j;
	}
	j = 0;

	BigInteger tmp2;
	tmp2.sign_ = X.sign_;
	tmp2.size_ = X.size_;
	for (int i = X.size_ - 1; i >= 0; --i) {
		tmp2.value_[j] = X.value_[i];
		++j;
	}

	BigInteger result;
	if(tmp1.size_ > tmp2.size_) {
		result.size_ = tmp1.size_ + 1;
	} else {
		result.size_ = tmp2.size_ + 1;
	}

	bool flag = false;
	if(tmp1.sign_ == tmp2.sign_) {
		for (int i = 0; i < result.size_ ; ++i) {
			if ((tmp1.value_[i] + tmp2.value_[i]) > 9) {
				result.value_[i] = (tmp1.value_[i] + tmp2.value_[i]) % 10;
				flag = true;
			} else {
				if(flag) {
					if ((tmp1.value_[i] + tmp2.value_[i] + 1) > 9) {
						result.value_[i] = (tmp1.value_[i] + tmp2.value_[i] + 1) % 10;
						flag = true;
					} else {
						result.value_[i] = tmp1.value_[i] + tmp2.value_[i] + 1;
						flag = false;
					}
				} else {
					result.value_[i] = tmp1.value_[i] + tmp2.value_[i];
				}
			}
		}
		result.sign_ = tmp1.sign_;
		result.deleteZero();
		result.reverse();
		return result;
	} else if((tmp1.sign_ == true && tmp2.sign_ == false) || (tmp1.sign_ == false && tmp2.sign_ == true)) {
		if (tmp1.size_ > tmp2.size_) {
			for (int i = 0; i < result.size_; ++i) {
				if ((tmp1.value_[i] - tmp2.value_[i]) < 0) {
					if(flag) {
						tmp1.value_[i] = tmp1.value_[i] + 9;
						result.value_[i] = tmp1.value_[i] - tmp2.value_[i];
						flag = true;
					} else {
						tmp1.value_[i] = tmp1.value_[i] + 10;
						result.value_[i] = tmp1.value_[i] - tmp2.value_[i];
						flag = true;
					}
					
				} else {
					if(flag == true) {
						if(tmp2.value_[i] == 0) {
							if (tmp1.value_[i] - 1 < 0) {
								result.value_[i] = 9;
								flag = true;
							}
							else {
								result.value_[i] = tmp1.value_[i] - 1;
								flag = false;
							}
						} else {
							if (tmp1.value_[i] - tmp2.value_[i] - 1 < 0) {
								tmp1.value_[i] = tmp1.value_[i] + 10;
								result.value_[i] = tmp1.value_[i] - tmp2.value_[i];
								flag = true;
							} else {
								result.value_[i] = tmp1.value_[i] - tmp2.value_[i] - 1;
								flag = false;
							}
						}
					} else {
						result.value_[i] = tmp1.value_[i] - tmp2.value_[i];
					}
				}
			}
			result.sign_ = tmp1.sign_;
			result.deleteZero();
			result.reverse();
			return result;
		} else if (tmp2.size_ > tmp1.size_) {
			for (int i = 0; i < result.size_; ++i) {
				if ((tmp2.value_[i] - tmp1.value_[i]) < 0) {
					if (flag) {
						tmp2.value_[i] = tmp2.value_[i] + 9;
						result.value_[i] = tmp2.value_[i] - tmp1.value_[i];
						flag = true;
					} else {
						tmp2.value_[i] = tmp2.value_[i] + 10;
						result.value_[i] = tmp2.value_[i] - tmp1.value_[i];
						flag = true;
					}

				} else {
					if (flag == true) {
						if (tmp1.value_[i] == 0) {
							if (tmp2.value_[i] - 1 < 0) {
								result.value_[i] = 9;
								flag = true;
							} else {
								result.value_[i] = tmp2.value_[i] - 1;
								flag = false;
							}
						} else {
							if (tmp2.value_[i] - tmp1.value_[i] - 1 < 0) {
								tmp2.value_[i] = tmp2.value_[i] + 10;
								result.value_[i] = tmp2.value_[i] - tmp1.value_[i];
								flag = true;
							} else {
								result.value_[i] = tmp2.value_[i] - tmp1.value_[i] - 1;
								flag = false;
							}
						}
					} else {
						result.value_[i] = tmp2.value_[i] - tmp1.value_[i];
					}
				}
			}
			result.sign_ = tmp2.sign_;
			result.deleteZero();
			result.reverse();
			return result;
		} else if (tmp1.size_ == tmp2.size_) {
			tmp1.reverse();
			tmp2.reverse();
			for (int j = 0; j < result.size_; ++j) {
				if (tmp1.value_[j] > tmp2.value_[j]) {
					tmp1.reverse();
					tmp2.reverse();
					for (int i = 0; i < result.size_; ++i) {
						if ((tmp1.value_[i] - tmp2.value_[i]) < 0) {
							tmp1.value_[i] = tmp1.value_[i] + 10;
							result.value_[i] = tmp1.value_[i] - tmp2.value_[i];
							flag = true;
						} else {
							if (flag == true) {
								if (tmp1.value_[i] - tmp2.value_[i] - 1 < 0) {
									tmp1.value_[i] = tmp1.value_[i] + 10;
									result.value_[i] = tmp1.value_[i] - tmp2.value_[i];
									flag = true;
								} else {
									result.value_[i] = tmp1.value_[i] - tmp2.value_[i] - 1;
									flag = false;
								}
							} else {
								result.value_[i] = tmp1.value_[i] - tmp2.value_[i];
							}
						}
					}
					result.sign_ = tmp1.sign_;
					result.deleteZero();
					result.reverse();
					return result;
				} else if(tmp2.value_[j] > tmp1.value_[j]) {
					tmp1.reverse();
					tmp2.reverse();
					for (int i = 0; i < result.size_; ++i) {
						if ((tmp2.value_[i] - tmp1.value_[i]) < 0) {
							tmp2.value_[i] = tmp2.value_[i] + 10;
							result.value_[i] = tmp2.value_[i] - tmp1.value_[i];
							flag = true;
						} else {
							if (flag == true) {
								if (tmp2.value_[i] - tmp1.value_[i] - 1 < 0) {
									tmp2.value_[i] = tmp2.value_[i] + 10;
									result.value_[i] = tmp2.value_[i] - tmp1.value_[i];
									flag = true;
								} else {
									result.value_[i] = tmp2.value_[i] - tmp1.value_[i] - 1;
									flag = false;
								}
							} else {
								result.value_[i] = tmp2.value_[i] - tmp1.value_[i];
							}
						}
					}
					result.sign_ = tmp2.sign_;
					result.deleteZero();
					result.reverse();
					return result;
				}
			}
		}
		result.deleteZero();
		result.reverse();
		return result;
	}
	//return *this;
}

BigInteger BigInteger::operator-(const BigInteger& X) const {
	BigInteger tmp1;
	BigInteger tmp2;
	BigInteger result;
	tmp1 = *this;
	tmp2 = X;
	tmp2.sign_ = (tmp2.sign_ == false) ? true : false;
	result = tmp1 + tmp2;
	return result;
}

BigInteger BigInteger::operator*(const BigInteger& X) const {
	BigInteger tmp1;
	tmp1.sign_ = sign_;
	tmp1.size_ = size_;
	int j = 0;
	for (int i = size_ - 1; i >= 0; --i) {
		tmp1.value_[j] = value_[i];
		++j;
	}
	j = 0;

	BigInteger tmp2;
	tmp2.sign_ = X.sign_;
	tmp2.size_ = X.size_;
	for (int i = X.size_ - 1; i >= 0; --i) {
		tmp2.value_[j] = X.value_[i];
		++j;
	}

	BigInteger result;
	result.size_ = tmp1.size_ + tmp2.size_ + 1;
	for(int i = 0; i < tmp1.size_; ++i) {
		for(int j = 0; j < tmp2.size_; ++j) {
			result.value_[i + j] = result.value_[i + j] + (tmp1.value_[i] * tmp2.value_[j]);
		}
	}
	for (int i = 0; i < result.size_; ++i) {
		result.value_[i + 1] = result.value_[i + 1] + (result.value_[i] / 10);
		result.value_[i] = result.value_[i] % 10;
	}
	if(tmp1.sign_ == tmp2.sign_) {
		result.sign_ = true;
	} else {
		result.sign_ = false;
	}
	result.deleteZero();
	result.reverse();
	return result;
}


BigInteger BigInteger::operator/(const BigInteger& X) const {
	BigInteger tmp1 = *this;

	BigInteger tmp2 = X;

	BigInteger tmp3;


	int t = 0;

	BigInteger result;

	result.size_ = (tmp1.size_ > tmp2.size_) ? tmp1.size_ : tmp2.size_;
	tmp1.sign_ = true;
	tmp2.sign_ = true;
	if(tmp1 == 0 || tmp2 == 0) {
		result = 0;
		return result;
	} else if (tmp1.size_ == tmp2.size_) {
		for (int i = 0; i <= 10; ++i) {
			if (tmp1 - tmp2 >= 0) {
				tmp1 = tmp1 - tmp2;
				std::cout << "1 tmp1 = " << tmp1 << ", size = " << tmp1.size_ << std::endl;
				++result;
			} else {
				result.sign_ = (tmp1.sign_ == tmp2.sign_) ? true : false;
				result.deleteZero();
				return result ;
			}
		}
	} else if(tmp1.size_ > tmp2.size_) {
		while(tmp1 > tmp2) {

			for (int i = 0; i < tmp2.size_ ; ++i) {
				tmp3.value_[i] = tmp1.value_[i];
			}
			tmp3.size_ = tmp2.size_;
			std::cout << "1 tmp2 = " << tmp2 << ", size = " << tmp2.size_ << std::endl;
			std::cout << "1 tmp3 = " << tmp3 << ", size = " << tmp3.size_ << std::endl;

			if(tmp2 > tmp3) {
				tmp3.value_[tmp3.size_] = tmp1.value_[tmp3.size_];
			
			}

			std::cout << "1 tmp2 = " << tmp2 << ", size = " << tmp2.size_ << std::endl;
			std::cout << "1 tmp3 = " << tmp3 << ", size = " << tmp3.size_ << std::endl;


			std::cout << std::endl;


			for (int i = 0; i <= 10; ++i) {
				if (tmp3 - tmp2 >= 0) {
					tmp3 = tmp3 - tmp2;
					std::cout << "1 tmp3 = " << tmp3 << ", size = " << tmp3.size_ << std::endl;

					++t;
				} else {
					break;
				}
			}std::cout << std::endl;

			std::cout << std::endl;
			std::cout << "3 tmp3 = " << tmp3 << ", size = " << tmp3.size_ << ", t = " << t << std::endl;
			tmp3 = tmp2 * t;
			tmp3.size_ = tmp1.size_;
			std::cout << "==================== " << tmp1 << " - "<<   tmp3 <<  std::endl;
			int tmp_size = tmp1.size_;
			tmp1 = tmp1 -  tmp3;


			std::cout << "++++++++++++++" << tmp1 << std::endl;

			if(tmp_size + 1 != tmp1.size_) {
				result = result + t;
				result *= 10;
			} else {
				result *= 10;
				result  = result + t;
			}

			t = 0;
			tmp3 = 0;

			std::cout << "tmp1 = " << tmp1 << ", size = " << tmp1.size_ << "    " << result << std::endl;
			std::cout << std::endl;
		}
	}
	tmp1.sign_ = this->sign_;
	tmp2.sign_ = X.sign_;
	if (tmp1.sign_ == tmp2.sign_) {
		result.sign_ = true;
	} else {
		result.sign_ = false;
	}

	return result;
	



}


// краткая форма операций
BigInteger& BigInteger::operator+=(const BigInteger& X) {
	BigInteger tmp1 = *this;
	BigInteger tmp2 = X;
	tmp1 = tmp1 + tmp2;
	*this = tmp1;
	return *this;
}

BigInteger& BigInteger::operator-=(const BigInteger& X) {
	BigInteger tmp1 = *this;
	BigInteger tmp2 = X;
	tmp1 = tmp1 - tmp2;
	*this = tmp1;
	return *this;
}

BigInteger& BigInteger::operator*=(const BigInteger& X) {
	BigInteger tmp1 = *this;
	BigInteger tmp2 = X;
	tmp1 = tmp1 * tmp2;
	*this = tmp1;
	return *this;
}






// префиксная форма
BigInteger& BigInteger::operator++() {
	return *this += 1 ;
};

BigInteger& BigInteger::operator--() {
	return *this -= 1;
};

// постфиксная форма
BigInteger BigInteger::operator++(int x) {
	BigInteger tmp1;
	BigInteger tmp2(1);
	tmp1 = *this;
	tmp1 = tmp1 + tmp2;
	*this = tmp1;
	return *this;
};

BigInteger BigInteger::operator--(int x) {
	BigInteger tmp1;
	BigInteger tmp2(1);
	tmp1 = *this;
	tmp1 = tmp1 - tmp2;
	*this = tmp1;
	return *this;
};




