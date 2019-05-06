#include <iostream>
#include <string>

/////////////////////////////////////////////////////////////////////////////////////////
class Advertising {

protected:
	std::string title;
	std::string customer;

public:

	Advertising();
	Advertising(const std::string& title, const std::string& customer);

	const std::string getTitle() const;
	void setTitle(const std::string &title);
	const std::string getCustomer() const;
	void setCustomer(const std::string &customer);

	virtual double getPrice() const = 0;
	virtual std::string print() const = 0;
};

Advertising::Advertising()
{
	title = "NO_TITLE";
	customer = "SOMEBODY";
}
Advertising::Advertising(const std::string& title, const std::string& customer)
{
	Advertising::title = title;
	Advertising::customer = customer;
}

const std::string Advertising::getTitle() const
{
	return title;
}
void Advertising::setTitle(const std::string &title)
{
	Advertising::title = title;
}
const std::string Advertising::getCustomer() const
{
	return customer;
}
void Advertising::setCustomer(const std::string &customer)
{
	Advertising::customer = customer;
}
/////////////////////////////////////////////////////////////////////////////////////////
class Board {

private:
	double width;
	double height;

public:
	Board();
	Board(double width, double height);

	double getWidth() const;
	void setWidth(double width);
	double getHeight() const;
	void setHeight(double height);

};

Board::Board()
{
	width = 0;
	height = 0;
}
Board::Board(double width, double height)
{
	Board::width = width;
	Board::height = height;
}

double Board::getWidth() const
{
	return width;
}
void Board::setWidth(double width)
{
	Board::width = width;
}
double Board::getHeight() const
{
	return height;
}
void Board::setHeight(double height)
{
	Board::height = height;
}
/////////////////////////////////////////////////////////////////////////////////////////
class AdvertisingInNewspaper : public Advertising {

	std::string name;
	Board board;
	int pricePerCentimeter;
	double price;

public:

	AdvertisingInNewspaper();
	AdvertisingInNewspaper(const std::string& title,
		const std::string& customer,
		const std::string& name,
		const double width, const double height,
		const int pricePerMeter);
	AdvertisingInNewspaper(const AdvertisingInNewspaper &ad);

	const std::string getName() const;
	void setName(const std::string &name);
	const Board getBoard() const;
	void setBoard(const Board &board);
	int getPricePerCentimeter() const;
	void setPricePerCentimeter(int pricePerMeter);
	double getPrice() const;

	std::string print() const;
	AdvertisingInNewspaper& operator= (const AdvertisingInNewspaper& ad);
};

AdvertisingInNewspaper::AdvertisingInNewspaper() : Advertising()
{
	AdvertisingInNewspaper::name = "NEWSPAPER";
	pricePerCentimeter = 1;
	price = 0;
}
AdvertisingInNewspaper::AdvertisingInNewspaper(const std::string& name,
	const std::string& title,
	const std::string& customer,
	const double width, const double height,
	const int pricePerMeter) : Advertising(customer, name)
{
	AdvertisingInNewspaper::name = name;
	board.setWidth(width);
	board.setHeight(height);
	AdvertisingInNewspaper::pricePerCentimeter = pricePerMeter;
	AdvertisingInNewspaper::price = board.getWidth() * board.getHeight() * pricePerMeter;
}
AdvertisingInNewspaper::AdvertisingInNewspaper(const AdvertisingInNewspaper &ad)
{
	AdvertisingInNewspaper::name = ad.getName();
	board.setWidth(ad.getBoard().getWidth());
	board.setHeight(ad.getBoard().getHeight());
	AdvertisingInNewspaper::pricePerCentimeter = ad.getPricePerCentimeter();
	AdvertisingInNewspaper::price = ad.getPrice();
}


const std::string AdvertisingInNewspaper::getName() const
{
	return name;
}
void AdvertisingInNewspaper::setName(const std::string &name)
{
	AdvertisingInNewspaper::name = name;
}
const Board AdvertisingInNewspaper::getBoard() const
{
	return board;
}
void AdvertisingInNewspaper::setBoard(const Board &board)
{
	AdvertisingInNewspaper::board = board;
}
int AdvertisingInNewspaper::getPricePerCentimeter() const
{
	return pricePerCentimeter;
}
void AdvertisingInNewspaper::setPricePerCentimeter(int pricePerMeter)
{
	AdvertisingInNewspaper::pricePerCentimeter = pricePerMeter;
}
double AdvertisingInNewspaper::getPrice() const
{
	return price;
}

std::string AdvertisingInNewspaper::print() const
{
	return
		+"Газета: " + name + "\n"
		+ "Назва: " + title + "\n"
		+ "Замовник: " + customer + "\n"
		+ "Білборд розмір: " + std::to_string(board.getWidth()) + " x " + std::to_string(board.getHeight()) + "\n"
		+ "Ціна: " + std::to_string((int)price) + "\n";

}
AdvertisingInNewspaper& AdvertisingInNewspaper::operator=(const AdvertisingInNewspaper& ad)
{
	AdvertisingInNewspaper::name = ad.getName();
	board.setWidth(ad.getBoard().getWidth());
	board.setHeight(ad.getBoard().getHeight());
	AdvertisingInNewspaper::pricePerCentimeter = ad.getPricePerCentimeter();
	AdvertisingInNewspaper::price = ad.getPrice();

	return *this;
}


/////////////////////////////////////////////////////////////////////////////////////////
class AdvertisingInBillboard : public Advertising {

private:
	std::string place;
	Board board;
	int numOfDays;
	int pricePerCentimeterForOneDay;
	double price;

public:

	AdvertisingInBillboard();
	AdvertisingInBillboard(const std::string& title,
		const std::string& customer,
		const std::string& place,
		const double width, const double height,
		const int numOfDay,
		const int pricePerMeter);
	AdvertisingInBillboard(const AdvertisingInBillboard& ad);

	const std::string &getPlace() const;
	void setPlace(const std::string &place);
	const Board getBoard() const;
	void setBoard(const Board &board);
	int getNumOfDays() const;
	void setNumOfDays(int numOfDays);
	int getPricePerCentimeterForOneDay() const;
	void setPricePerCentimeterForOneDay(int pricePerCentimeterForOneDay);
	double getPrice() const;
	void setPrice(double price);

	std::string print() const;
	AdvertisingInBillboard& operator= (const AdvertisingInBillboard& ad);
};

const std::string &AdvertisingInBillboard::getPlace() const
{
	return place;
}
void AdvertisingInBillboard::setPlace(const std::string &place)
{
	AdvertisingInBillboard::place = place;
}
const Board AdvertisingInBillboard::getBoard() const
{
	return board;
}
void AdvertisingInBillboard::setBoard(const Board &board)
{
	AdvertisingInBillboard::board = board;
}
int AdvertisingInBillboard::getNumOfDays() const
{
	return numOfDays;
}
void AdvertisingInBillboard::setNumOfDays(int numOfDays)
{
	AdvertisingInBillboard::numOfDays = numOfDays;
}
int AdvertisingInBillboard::getPricePerCentimeterForOneDay() const
{
	return pricePerCentimeterForOneDay;
}
void AdvertisingInBillboard::setPricePerCentimeterForOneDay(int pricePerCentimeterForOneDay)
{
	AdvertisingInBillboard::pricePerCentimeterForOneDay = pricePerCentimeterForOneDay;
}
double AdvertisingInBillboard::getPrice() const
{
	return price;
}
void AdvertisingInBillboard::setPrice(double price)
{
	AdvertisingInBillboard::price = price;
}

AdvertisingInBillboard::AdvertisingInBillboard()
{
	place = "PLACE";
	numOfDays = 0;
	pricePerCentimeterForOneDay = 0;
}
AdvertisingInBillboard::AdvertisingInBillboard(const std::string &title,
	const std::string &customer,
	const std::string &place,
	const double width, const double height,
	const int numOfDay,
	const int pricePerCentimeterForOneDay) : Advertising(title, customer)
{
	AdvertisingInBillboard::place = place;
	board.setWidth(width);
	board.setHeight(height);
	AdvertisingInBillboard::numOfDays = numOfDay;
	AdvertisingInBillboard::pricePerCentimeterForOneDay = pricePerCentimeterForOneDay;
	AdvertisingInBillboard::price = width * height * numOfDay * pricePerCentimeterForOneDay;
}
AdvertisingInBillboard::AdvertisingInBillboard(const AdvertisingInBillboard &ad)
{
	Advertising::title = ad.getTitle();
	Advertising::customer = ad.getCustomer();
	AdvertisingInBillboard::place = ad.place;
	board.setWidth(ad.getBoard().getWidth());
	board.setHeight(ad.getBoard().getHeight());
	AdvertisingInBillboard::numOfDays = ad.getNumOfDays();
	AdvertisingInBillboard::pricePerCentimeterForOneDay = ad.getPricePerCentimeterForOneDay();
	AdvertisingInBillboard::price = ad.getPrice();
}

std::string AdvertisingInBillboard::print() const
{
	return  "Місце: " + place + "\n"
		+ "Назва: " + title + "\n"
		+ "Замовник: " + customer + "\n"
		+ "Білборд розмір: " + std::to_string(board.getWidth()) + " x " + std::to_string(board.getHeight()) + "\n"
		+ "Ціна: " + std::to_string((int)price) + "\n";
}
AdvertisingInBillboard &AdvertisingInBillboard::operator=(const AdvertisingInBillboard &ad)
{
	Advertising::title = ad.getTitle();
	Advertising::customer = ad.getCustomer();
	AdvertisingInBillboard::place = ad.place;
	board.setWidth(ad.getBoard().getWidth());
	board.setHeight(ad.getBoard().getHeight());
	AdvertisingInBillboard::numOfDays = ad.getNumOfDays();
	AdvertisingInBillboard::pricePerCentimeterForOneDay = ad.getPricePerCentimeterForOneDay();
	AdvertisingInBillboard::price = ad.getPrice();

	return *this;
}

void printAds(int size, Advertising* ads[]);
double summaryPriceOf(int size, Advertising* ads[]);
void sort(int size, Advertising* ads[]);

using namespace std;


int main()
{
	system("chcp 1251");

	AdvertisingInNewspaper adPaper1("Ранок", "Робота", "Ігор", 40, 30, 2);
	AdvertisingInNewspaper adPaper2("Люкс", "Театр", "Данило", 38, 34, 3);

	AdvertisingInBillboard adBillboard1("Виступ рок групи", "Іван", "вул. Бандери", 25, 34, 14, 12);
	AdvertisingInBillboard adBillboard2("Виступ рок групи", "Іван", "вул. Бандери", 20, 10, 28, 10);

	const int SIZE = 4;
	Advertising* ads[SIZE] = { &adPaper1, &adBillboard1, &adPaper2, &adBillboard2 };

	sort(SIZE, ads);
	printAds(SIZE, ads);

	cout << "Сумарна вартість: " << summaryPriceOf(SIZE, ads) << endl;

	system("pause");
	return 0;
}

double summaryPriceOf(int size, Advertising* ads[])
{
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += ads[i]->getPrice();
	return sum;
}
void printAds(int size, Advertising* ads[])
{
	for (int i = 0; i < size; i++)
		cout << ads[i]->print() << endl;
}
void sort(int size, Advertising* ads[])
{
	//Сортування вставкою
	Advertising* temp;
	int item;
	for (int counter = 1; counter < size; counter++)
	{
		temp = ads[counter];
		item = counter - 1;
		while (item >= 0 && ads[item]->getPrice() < temp->getPrice())
		{
			ads[item + 1] = ads[item];
			ads[item] = temp;
			item--;
		}
	}
}
