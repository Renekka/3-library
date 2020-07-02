#include <iostream>
#include <boost/optional.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/time_zone_base.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <locale>  
#include <iomanip>

using namespace boost::gregorian;
using namespace boost::posix_time;
using namespace boost::local_time;
using namespace std;

class DATA
{
	tz_database file;
	string h;
	int day;
	int month;
public:
	DATA() {}
	DATA(string h, int day, int month)
	{
		this->h = h;
		this->day = day;
		this->month = month;
	}
	void files()
	{
		file.load_from_file("C:\\Users\\а843\\Desktop\\boost\\boost_1_73_0\\libs\\date_time\\data\\date_time_zonespec.csv");
	}
	void REGION()
	{
		const vector<string>& all = file.region_list();
		vector<string>::const_iterator it = all.begin(); 
		//итератор для доступа к файлам
		cout << "______________________________________________________________________\n";
		cout << "|" << setw(35) << left  << "     Название региона" << setw(10) << "|" << setw(23) << "Часовой пояс региона" << setw(15) << "|" << endl;
		cout << "______________________________________________________________________\n";
		for (int i = 1; it != all.end(); i++, it++)
		{
			time_zone_ptr x = file.time_zone_from_region(*it);
			cout << "|" << setw(35) << left << *it << setw(10) << "|" << setw(23) << file.time_zone_from_region(*it)->std_zone_name() << setw(15) << "|" << endl;
		}
		cin.get();
	}
	void Time()
	{
		cout << "Введите желаемую зону в формате << Europe/Moscow >> \n";
		cin >> h; 
		time_zone_ptr timc = file.time_zone_from_region(h); //обращение к часовым зонам из файла буста
		cout << "Начало перевода на летнее время: \n";
		cout << file.time_zone_from_region(h)->dst_local_start_time(2020)<< endl;
		cout << "Конец перевода на летнее время: \n";
		cout << file.time_zone_from_region(h)->dst_local_end_time(2020) << endl;
		cin.get();
	}
	void Space()
	{ 
		cout << "Введите день: ";
		cin >> day;
		cout << "Введите месяц: "; 
		cin >> month;
		
		partial_date pd(day, month);
		date today = day_clock::local_day();
		date d = pd.get_date(today.year());

		partial_date day_(5, Jul);
		days days_ = day_.get_date(today.year()) - d;
		//грубо говоря, от указанной в коде даты отнимаем дату, введенную пользователем.
		if (days_.days() > 0)
		{
			cout << "\nДней до лунного затмения: " << days_.days() << endl;
			cout << "Четвертое затмение года будет полутеневым лунным и произойдет в полнолуние 5 июля. \n"
				<< "Это затмение совсем не будет видно на территории России,\n"
				<< "а область видимости его распространится на американский континент и Западную Африку.\n";
		}
		if (days_.days() < 0)
		{
			cout << "\nЛунное затмение уже прошло " << days_.days() * (-1) << " дней назад\n"; 
			//если кол-во дней < 0, это значит, что дата уже прошла, и мы убираем "-" чтобы вывести дни
		}
		if (days_.days() == 0)
		{
			cout << "\nЛунное затмение уже сегодня! " << endl;
			cout << "Четвертое затмение года будет полутеневым лунным и произойдет в полнолуние 5 июля. \n"
				<< "Это затмение совсем не будет видно на территории России,\n"
				<< "а область видимости его распространится на американский континент и Западную Африку.\n";
		}

		partial_date day2(21, Jun);
		days days2_ = day2.get_date(today.year()) - d;
		if (days2_.days() > 0)
		{
			cout << "\nДней до солнечного затмения: " << days2_.days() << endl;
			cout << "Третье затмение 2020 года будет кольцеобразным солнечным.\n"
				<< "Оно произойдет при новолунии 21 июня, а полоса кольцеобразной фазы \n "
				<< "пройдет по территории Африки, Аравийского полуострова и азиатскому континенту.\n";
		}
		if (days2_.days() < 0)
		{
			cout << "\nСолнечное затмение уже прошло!\n" << days2_.days() * (-1) << " дней назад\n";
		}
		if (days2_.days() == 0)
		{
			cout << "\nСолнечное затмение уже сегодня!" << endl;
			cout << " Третье затмение 2020 года будет кольцеобразным солнечным.\n"
				<< "Оно произойдет при новолунии 21 июня, а полоса кольцеобразной фазы \n "
				<< "пройдет по территории Африки, Аравийского полуострова и азиатскому континенту.\n";
		}

		cin.get();
	} 
	void Local_time()
	{
		cout << "Ваша текущая системная дата: \n";
		date d = day_clock::universal_day(); //обращение к данным
		cout << "  " << d.day() << "-" << d.month() << "-" << d.year();

		cin.get();
	}
	void Menu()
	{
		cout << "\nИнформация, которую можно получить на нашем ресурсе:\n";
		cout << "0 - Название регионов и их часовых поясов\n1 - Перевод на летнее время\n2 - Асторономический календарь\n" <<
			"3 - Системная дата и время\n4 - Выход\n";
	}
};
