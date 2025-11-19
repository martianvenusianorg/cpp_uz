# Structure

Bazan har xil turdagi qiymatlar to'plamiga ega bo'lish va bu to'plamni yagona borliq deb qabul qilish foydalidir. Misol sifatida bankda omonat qo'yish uchun ochilgan maxsus bank hisob raqamingizni (azoligingizni) olaylik. Bu bank azoligida uchta ma'lumot mavjud: mavjud pul miqdori, omonat foiz ko'rsatgichi va pulni yechib olishgacha bo'lgan majburiy saqlash muddati. Dastlabgi ikki ma'lumotni *double* turdagi o'zgaruvchilar bilan ifodalash mumkin, va majburiy saqlash muddatini esa *int* turdagi o'zgaruvchi bilan ifodalash mumkin.

Bu ma'lumotlarni *structure* orqali quyidagicha ifodalaymiz:

```cpp
struct BankAccout
{
	double	balance;
	double	interestRate;
	int term; // pulni yechib olishgacha bo'lgan majburiy saqlash muddati
};
```

Bu yerda *`struct`* so'zi yordamida *structure* toifamizni yaratayotganimizni bildiryapmiz. `BankAccount` esa bu *structure* toifamizning nomidir. *Structure* toifasining nomi ***structure tag*** deb ham ataladi. Bu *tag* identifikatordir lekin *keyword* (dasturlash tilining sintaksisida mavjud bo'lgan maxsus so'z) emas. C++ dasturlash tili *structure* *tag* (*structure* nomi)ni nomlashda qatiy qoidalarni talab qilmasada, *structure tag*lar odatda katta va kich harflar orqali ifodalanadi va katta harf bilan boshlanadi. {} qavslari ichida e'lon qilingan identifikatorlar esa *structure* **a'zolari nomlari** (*member names*)dir. Yuqoridagi misolda ko'rsatilgani kabi *structure* toifa nuqta virgul (;) bilan tugaydi.

*Structure*ni e'lon qilish odatda har qanaqa funksiyalarni e'lon qilishdan oldin joylashtiriladi (huddi *global* *constant*ni e'lon qilish barcha funksiyalardan tashqarida joylashtirilgani kabi). Shunday qilinsa s*tructure* toifasini *structure* tuzilgandan keyin keladigan barcha kodlar uchun ishlatish imkonini beradi.

Bir marta *structure* toifasi tuzilganidan keyin, uni c++ tilida mavjud bo'lgan *int*, *char* va boshqa turlar kabi ishlatish mumkin bo'ladi. Misol uchun, `myAccount` va `yourAccount` nomlari bilan `BankAccount` toifali ikkita o'zgaruvchini quydagicha e'lon qilib ko'rishimiz mumkin:

```
BankAccout myAccount, yourAccount;
```

*Structure* toifali o'zgaruvchi qolgan har qanday o'zgaruvchi qiymat saqlagani kabi o'zida qiymat saqlaydi. *Structure*ning qiymati (*structure value*) **a'zo qiymat**lar (*member values*) deb ataluvchi kichikroq qiymatlar to'plamidir. Misol uchun, `BankAccout` toifadagi *structure* qiymati bu uchta a'zo qiymatlarning to'plamidir: ikkita *double* tur va bitta *int* tur.  Birgalikda s*tructure* qiymatini tashkil etuvchi bu a'zo qiymatlar **a'zo o'zgaruvchi**lar (*member variables*)da saqlanadi.

Har bir *structure* o'zining a'zolari nomlarini e'lon qiladi. Quydagi misolda `BankAccount` uchta a'zo nomlariga ega: `balance`, `interestRate` va `term`.

---

**DASTUR 1**

```cpp
// BankAccount structure toifasini ifodalovchi dastur
#include <iostream>
using namespace std;
// Bank omonat daftarchasi uchun structure
struct BankAccount
{
	double	balance;
	double	interestRate;
	int term; // yechib olgunga qadar bo'lgan majburiy saqlash muddati
};

void getData(BankAccount& theAccount);
// Keyingi holat: theAccount.balance va theAccount.interestRate
// berilgan qiymatlar foydalanuvchi tomonidan kiritiladi.

int main()
{
	BankAccount account;
	getData(account);

	double rateFraction, interest;
	rateFraction = account.interestRate / 100.0;
	interest = account.balance * rateFraction * (account.term / 12.0);
	account.balance = account.balance + interest;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout 	<< "Sizning omonatingiz "
		<< account.term << " oydan so'ng $" << account.balance << " bo'ladi." << endl;

	return 0;
}

// iostreamdan foydalaniladi.
void getData(BankAccount& theAccount)
{
	cout	<< "Mavjud pul miqdorini kiriting: $";
	cin	>> theAccount.balance;
	cout	<< "Foiz ko'rsatgichini kiriting: ";
	cin	>> theAccount.interestRate;
	cout	<< "Omonatni majburing saqlash muddatini ko'rsating\n"
		<< "(muddat 12 oy yoki undan kichik bo'lishi kerak): ";
	cin	>> theAccount.term;
}
```

```
Mavjud pul miqdorini kiriting: $100.00
Foiz ko'rsatgichini kiriting: 10.0
Omonatni majburing saqlash muddatini ko'rsating
(muddat 12 oy yoki undan kichik bo'lishi kerak): 6
Sizning omonatingiz 6 oydan so'ng $105.00 bo'ladi.
```

Ushbu a'zo nomlarning har biri bilan kattaroq *structure* toifali o'zgaruvchining tarkibiy qismi bo'lgan kichikroq o'zgaruvchini tanlash uchun ishlatish mumkin. Bu kichkina o'zgaruvchilar **a'zo o'zgaruvchi**lar (***member variables***) deb nomlanadi. Azo o'zgaruvchilarga *structure* toifali o'zgaruvchining nomidan keyin nuqta (.) va undan keyin a'zo nomi ko'rsatilishi orqali murojaat qilinadi. Misol uchun, agar `account`  `BankAccount` toifali *structure* o'zgaruvchi bo'lsa, unda *structure* o'zgaruvchi `account` qo'ydagi uchta a'zolarga ega bo'ladi.

```
account.balance
account.interestRate
account.term
```

Birinchi ikkita o'zgaruvchi *double* tur va oxirgi o'zgaruvchi *int* turdir. Bu a'zo o'zgaruvchilar xuddi shu turdagi boshqa har qanday o'zgaruvchi kabi ishlatilishi mumkin. Misol uchun, yuqoridagi a'zo o'zgaruvchilarga quyidagi uchta o'zlashtirishni amalga oshirish orqali qiymat berish mumkin.

```
account.balance = 1000.0;
account.interestRate = 4.7;
account.term = 11;
```

Keyingi misolda bu uchta amalning natijasini ko'rishimiz mumkin:

```cpp
struct Account
{
	double balance;
	double interestRate;
	int term;
}
int main()
{
	BankAccount account; 		// account {balance = ?, interestRate = ?, term = ?}

	account.balance = 1000.00;	// account {balance = 1000.00, interestRate = ?, term = ?}

	count.interestRate = 4.7;	// account {balance = 1000.00, interestRate = 4.7, term = ?}

	account.term = 11;		// account {balance = 1000.00, interestRate = 4.7, term = 11}
}
```

Azo o'zgaruvchilar oddiy o'zgaruvchilar singari har qanday usullarda ishlatilishi mumkin. Misol uchun, yuqorida ko'rgan birinchi dasturimizning quyidagi qatori `account.balance` a'zo o'zgaruvchisining qiymatini odatiy o'zgaruvchi `interest` qiymatiga qo'shadi va keyin natijani yana a'zo o'zgaruvchi `account.balance`ga o'zlashtiradi.

```
account.balance = account.balance + interest;
```

Huddi shu usulda yani nuqta (.) operatori yordamida *structure*ning a'zo funksiyalaridan ham foydalanish mumkin. Bu yerda faqat farq shundaki, *structure*ning a'zolari funksiya emas balki o'zgaruvchilardir. *Class*ning a'zo o'zgaruvchilari va a'zo funksiyalari haqida keyingi bo'limlarimizda ko'rib chiqamiz.

Ikki yoki undan ortiq *structure* toifalar bir xil nomli a'zo o'zgaruvchilarga ega bo'lishi mumkin. Buni quydagi misolda ko'rishimiz mumkin:

```cpp
struct FetilizerStock
{
	double quantity;
	double nitrogenContent;
}

struct CropYield
{
	int quantity;
	double size;
}
```

Yuqoridagi misolimizda ko'rganimiz kabi bir xil nom ostida a'zo o'zgaruvchilarga ega bo'lish *structure*lar uchun muammo tug'dirmaydi. Misol uchun, ikkita *structure*ning o'zgaruvchilarini quydagicha e'lon qilsak bo'ladi:

```
FertilizerStock superGrow;
CropYield apples;
```

Bunda `superGrow`ning `quantitiy` qiymati `superGrow.quantity` a'zo o'zgaruvchisiga va `apples`ning `quantitiy` qiymati `apple.quantitiy` a'zo o'zgaruvchisiga o'zlashtiriladi. Nuqta operatori va *structure*ning a'zo o'zgaruvchisi nomi har bir holatda qaysi qiymat nazarga tutilayotganini belgilab beradi.

*Structure*ning qiymati (*structure value*)ni a'zo qiymatlar (member values)ning to'plami sifatida ko'rish mumkin. *Structure*ning qiymatida ko'plab qiymatlar mavjud bo'lishi mumkin. *Structure*ning qiymatini yagona (murakkab) qiymat sifatida ham ko'rish mumkin (yani, a'zo qiymatlardan tashkel topgan yagona qiymat). Shunday qilib *structure*ning qiymatini yagona qiymat sifatida ko'rish mumkin bo'lganligi sababli, *structure*ning qiymati (*structure value*) va *structure* o'zgaruvchisi (*structure varaible*)ni c++ dasturlash tilida mavjud bo'lgan *int* yoki *double* kabi oddiy o'zgaruvchi (variable) va oddiy qiymatlar (value) singari ishlatish mumkin. Ayniqsa, = tenglik belgisi yordamida *structure*ning qiymatini ham o'zlashtirish mumkin. Misol uchun, agar `apple` va `orange` yuqorida ko'rganimiz `GropYield` *structure*ning o'zgaruvchilar bo'ladigan bo'lsa, unda quydagi amal mutlaqo c++ dasturi uchun qoniniy bo'ladi:

```
apples = oranges;
```

Bu o'zlashtirish amali quydagi misolga tengdir:

```
apples.quantity = oranges.quantity;
apples.size = oranges.size;
```

Biz *structure*ning qiymatini shunaqa yusunda o'zlashtirishimiz **sayoz nusxalash** (**shallow copy**) deb ataladi. Bu degani har bir a'zo o'zgaruvchilar to'g'ridan to'g'ni o'zlashtiriladi. Va bu oddiy o'zgaruvchilar uchun muammo tug'dirmaydi. Lekin bu o'zgaruvchilarni mashina xotirasiga dinamik taqsimlash shaklida yozadigan bo'lsak muammo kelib chiqishi mumkin. Bu haqda keyingi bo'limlarimizda batafsil ko'rib chiqamiz.

---

#### **OGOH BO'LING:** ***Structure***ni e'lon qilayotganingizda nuqta-vergul qo'yishni unutmang.

Qachonki oxirgi } qavsni *structure*ning tugashiga qo'shganimizda, go'yoki *structure*ni yaratish tugaganidek his qilamiz, lekin aslida unday emas. Bu ko'p ham ahamiyat kasb etmaydigan o'ziga xos husisiya bo'lsa ham siz *structure*ning oxirgi } qavsidan keyin ; nuqta-vergulni qo'yishingiz kerak. *Structure*ni tafsivlash bu shunchaki faqat *structure* yaratishni bildirmaydi, balki biz *structure* yaratish mobaynida o'zgaruvchilarini ham e'lon qilib ketishimiz ham mumkin. Chunki siz } yakuniy qavs va ; nuqta-vergul orasida *structure*ning o'zgaruvchilar nomlari ro'yxatini berib ketishga ro'xsat etilgansiz. Misol uchun, quydagi misol WeatherData nomli *structure*ni yaratadi va ikkita WeatherData *structure* turdagi o'zgaruvchilar `dataPoint1` va `dataPoint2`ni e'lon qiladi:

```cpp
struct WeatherData
{
	double temperature;
	double windVelocity;
} dataPoint1, dataPoint2;
```

Biroq, aytib o'tganimizdek, biz har doim *structure* tavsifi va bu *structure* toifali o'zgaruvchilar e'lon qilinishini ajratamiz. Shuning uchun bizning *structure* tavsifimizda har doim oxirgi } yopiq qavsimizdan keyin ; nuqta-virgul bo'ladi.

---

> #### Nuqta operatori (The Dot Operation)
>
> Nuqta operatori *structure* toifali o'zgaruvchining a'zo o'zgaruvchisini belgilash uchun ishlatiladi.
>
> ```cpp
> struct StudentRecord
> {
> 	int studentNumber;
> 	char grade;
> };
>
> int main()
> {
> 	StudentRecord yourRecord;
> 	yourRecord.studentNumber = 2001;
> 	yourRecord.grade = 'A';
> } 
> ```
>
> Bazi yozuvchilar bu operatorni *the structure member access* (structure a'zosiga kirish) deb ham nomlashadi. Biz shunchaki *structure* a'zosiga murojaat qilish yo'li deb tushinsak ham bo'ladi.

### *Structure* Funksiya Argumentlari sifatida

Funksiya *structure* turdagi ***call-by-value*** parameterlariga va/yoki *structure* turdagi ***call-by-reference*** parameterlarga ega bo'lishi mumkin. Misol uchun, birinchi dasturimizda `getData` nomli funksiya bor va bu funkisya `BankAccount` *structure* toifali *call-by-reference* parameterga ega.

Qolaversan *structure* toifasining o'zi ham funksiyaning qaytarilgan qiymati uchun ma'lumot turi (data type) bo'lib xizmat qilishi mumkin. Masalan, quydagi misol uchta mos argumentlarni qabul qiladigan va `BankAccount` turidagi qiymatni qaytaradigan funksiyani ifodalaydi:

```cpp
BankAccount shrinkWrap(double theBalance, double theRate, int theTerm)
{
	BankAccount temp;
	temp.balance = theBalance;
	temp.interestRate = theRate;
	temp.term = theTerm;
	return temp;
}
```

E'tibor bering, `BankAccount` turdagi lokal o'zgaruvchi (local variable) `temp` yakuniy *structure* qiymatni tuzishda ishlatildi va bu o'zgaruvchi funksiya tomonidan qaytarilyapti. Siz `shrinkWrap` funksiyasini yaratganingizdan keyin quydagi misolda ko'rsatilganidek `BankAccount` turidagi o'zgaruvchiga qiymatni berishingiz mumklin:

```cpp
BankAccount newAccount;
newAccount = shrinkWrap(100000.00, 5.1, 11);
```

**MASLAHAT: Iyerarxik *Structure*lardan foydalaning**

Bazida *structure*ning a'zolarining o'zi boshqa bir kichikroq *structure* toifali bo'lishi mumkin. Misol uchun, insonning bo'yi, og'irligi va tug'ilgan kuni haqidagi ma'lumotlarni saqlovchi `PersonInfo` nomli *structure* toifani quydagicha ifodalashimiz mumkin:

```cpp
struct Date
{
	int month;
	int day;
	int year;
};

struct PersonInfo
{
	double height; 	// cm
	int weight;	// kg
	Date birthday;
};
```

`PersonInfo` *structure* turidagi o'zgaruvchi quyidagicha e'lon qilinishi mumkin:

```
PersonInfo person1;
```

Agar *structure* o'zgaruvchi `person1` o'zining insonning tu'gilgan sanasi ma'lumotlari to'plami qiymatiga ega bo'lsa, unda insonning tug'ilgan yilini quydagicha ko'rsatish mumkin.

```
cout << person1.birthday.year;
```

Bunda infodani o'qish chapdan o'nga bo'ladi va boshlang'ich nuqta `PersonInfo` turidagi *structure* o'zgaruvchi `person1`dir. `birthday` nomli a'zo o'zgaruvchiga ega bo'lish uchun nuqta operatoridan foydalanib quydagicha amalga oshiriladi:

```
person1.birthday
```

Bu a'zo o'zgaruvchining o'zi `Date` turidagi *structure* o'zgaruvchidir. Shunday qilib, bu a'zo o'zgaruvchining o'zi ham o'z a'zo o'zgaruvchilariga egadir. Yuqorida ko'rganimiz kabi `person1.birthday.year` ifodasini hosil qilishda *Structure* o'zgaruvchi `person1.birthday`ning o'zgaruvchisini qo'lga kiritish nuqta operatori va a'zo o'zgaruvchining nomini (misol uchun `year`) kiritish orqali qo'lga kiritildi.

---

> #### **Sodda *Structure* Turlari**
>
> ***Structure* toifa**sini quydagicha ifodalaysiz. ***Structure Tag*** bu *structure* turining nomidir.
>
> **SINTAKSIS**
>
> ```
> struct StructureTag
> {
> 	Tur1 A'zoO'zgaruvchiNomi1;
> 	Tur2 A'zoO'zgaruvchiNomi2;
> 	.
> 	.
> 	.
> 	TurN A'zoO'zgaruvchiNomiN;
>
> }; // Nuqta-virgul qo'yishni unutmang
> ```
>
> **MISOL:**
>
> ```cpp
> struct Automobile
> {  
> 	int year;
> 	int doors;
> 	double horsePower;
> 	char model;
> };
> ```
>
> ***Structure* toifaning o'zgaruvchilari** boshqa turdagi o'zgaruvchilar kabi e'lon qilishini mumkin.
>
> ```
> Automobile myCar, yourCar;
> ```
>
> A'zo o'zgaruvchilar **nuqta operatori** yordamida belgilanishi mumkin. Misol uchun,
>
> `myCar.year`, `myCar.doors`, `myCar.horsePower` va `myCar.model`

## *Structurelar*ni o'zlashtirish

Siz *structure*nining qiymatlarini *structure* e'lon qilinganida o'zlashtirishingiz mumkin. *Structure* toifali o'zgaruvchiga qiymat berish uchun = tenglik belgisidan keyin {} qavslar ichida a'zo qiymatlar ro'yxatini berib ketishingiz mumkin. Misol uchun, quydagi *structure* toifani ifodalash yuqoridagi bo'liblarda ko'rib o'tdik:

```cpp
struct Date
{
	int month;
	int day;
	int year;
}
```

`Date` turi yaratilganidan keyin `dueDate` nomli structure o'zgaruvchini quydagicha e'lon qilishingiz va qiymat o'zlashtirishingiz mumkin:

```
Date dueDate = {12, 31, 2004}
```

O'zlashtirilayotga qiymatlar *structure* turi yaratilgandagi a'zo o'zgaruvchilarga mos tartibda bo'lishiga e'tibor bering. Bu misolda `dueDate.month` birinchi qiymat 12ni, `dueDate.day` ikkinchi qiymat 31, va `deuDate.year` uchunchi qiymat 2004ni qabul qiladi.

Agar u yearda *structure* a'zolaridan ko'proq o'zlashtiruvchilar (*initializers*) bo'lsa xatolik ro'y beradi. Agar u yearda *structure* a'zolari sonidan kamroq o'zlashtiruvchilar bo'lsa, unda taqdim etilgan qiymatlar tartib bo'yicha ma'lumotlarni a'zolarga o'zlashtiradi. Har bir o'zlashtiruvchisiz qolgan a'zo o'zgaruvchi o'z turiga mos ravishda nol qiymatni qabul qiladi.
