# Structure va Class

Object (Obyekt) bu o'zgaruvchi bo'lib o'zining function (funksiya) azolariga ega. Class esa data type (ma'lumot turi) bo'lib uning azolari object (obyekt)lardir. Shunday qilib, class tushinchasini data typega doir 2 ta tarif bilan tushintirish kerak bo'ladi: (1) Classning o'zgaruvchilari qaysi toifadagi qiymatlarni o'zida saqlaydi va (2) classning a'zo function (funksiya)lari qanaqa bo'ladi. Class tushinchasini ikki bosqichda tushinishga xarakat qilamiz. Birinchi *structure* nima ekanligni o'rganamiz va data type tushinchasini tushinib olamiz. Bu bizga classning data type (ma'lumot turi) nima ekanligini tushinib olishimizga yordam beradi. Bu yerda o'zinig function azolariga ega bo'lmagan structure haqida gaplashamiz. Structure tushinchasini o'rganib olganimizdan keyin asonlik bilan class nima ekanligini o'rganib olishimiz mumkin bo'ladi.

## Structure

Bazan har xil turdagi qiymatlar to'plamiga ega bo'lish va bu to'plamni yagona borliq deb qabul qilish foydalidir. Misol sifatida bankda omonat qo'yish uchun ochilgan maxsus bank hisob raqamingizni (azoligingizni) olaylik. Bu bank azoligida uchta ma'lumot mavjud: mavjud pul miqdori, omonat foiz ko'rsatgichi va pulni yechib olishlarsiz majburiy saqlash muddati. Dastlabgi ikki ma'lumotni *double* toifadagili o'zgaruvchilar bilan ifodalash mumkin, va majburiy saqlash muddatni esa *int* toifaligi o'zgaruvchi bilan ifodalash mumkin.

Bu ma'lumotlarni *structure* orqali quyidagicha ifodalashimiz mumkin.

```cpp
struct BankAccout
{
	double	balance;
	double	interestRate;
	int term; // yechib olishga bo'lgan majburiy saqlash muddati
};
```

Bu yerda *struct* so'zi yordamida *structure* toifamizni yaratayotganimizni e'lon qilyapmiz. BankAccount esa bu *structure* toifamizning nomidir. *Structure* toifasining nomi **structure tag** deb ham ataladi. Bu *tag* identifikatordir lekin *keyword* (dasturlash tilining sintaksisida mavjud bo'lgan maxsus so'z) emas. C++ dasturlash tili *structure* *tag* (*structure* nomi)ni nomlashda qatiy qoidalarni talab qilmasada, *structure tag*lar odatda katta va kich harflar orqali ifodalanadi va katta harf bilan boshlanadi. {} qavslari ichida elon qilingan identifikatorlar esa *structure* azolari nomlaridir. Tuqoridagi misolda ko'rsatilgani kami *structure* toifa nuqta virgul (;) bilan tugaydi.

*Structure*ni e'lon qilish odatda har qanaqa funksiyalarni e'lon qilishdan tashqarida joylashtiriladi (huddi *global* *constant*ni e'lon qilish barcha funksiyalardan tashqarida joylashtirilgani kabi). Shundan keyin s*tructure* toifasini *structure* tarifidan keyin keladigan barcha kodlar uchun ishlatish mumkin bo'ladi.

Bir marta *structure* toifasi e'lon qilinganidan keyin, uni c++ tilida mavjud bo'lgan *int*, *char* va boshqa turlar kabi ishlatish mumkin bo'ladi. Misol uchun, myAccount va yourAccount nomlari bilan BankAccount toifali ikkita o'zgaruvchini quydagicha yaratib ko'rishimiz mumkin:

```cpp
BankAccout myAccount, yourAccount;
```

*Structure* toifali o'zgaruvchi qolgan har qanday o'zgaruvchi qiymat saqlagani kabi o'zida qiymat saqlaydi. *Structure*ning qiymati **a'zo qiymat**lar deb ataluvchi kichikroq qiymatlar to'plamidir. Misol uchun, BankAccout toifali qiymat bu uchta a'zo qiymatlarning to'plamidir: ikkita *double* toifa va bitta *int* toifa. Birgalikda s*tructure* qiymatini tashkil etuvchi bu a'zo qiymatlar a'zo o'zgaruvchilarda saqlanda saqlanadi.

Har bir *structure* o'zining a'zolari nomlarini e'lon qiladi. Quydagi misolda BankAccount uchta a'zo nomlariga ega: balance, interestRate va term.

```cpp
// BankAccount structure toifasini ifodalovchi dastur
#include <iostream>
using namespace std;
// Bank omonat daftarchasi uchun structure
struct BankAccount
{
	double	balance;
	double	interestRate;
	int term; // yechib olishga bo'lgan majburiy saqlash muddati
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

Ushbu a'zo nomlarning har biri bilan kattaroq *structure* toifali o'zgaruvchining bir qismi bo'lgan bitta kichikroq o'zgaruvchini tanlash uchun ishlatish mumkin. Bu kichkina o'zgaruvchilar a'zo o'zgaruvchilar deb nomlanadi. Azo o'zgaruvchilarga *structure* toifali o'zgaruvchining nomidan keyin nuqta (.) va undan keyin a'zo nomi ko'rsatilishi orqali murojaat qilinadi. Misol uchun, account BankAccount toifali *structure* o'zgaruvchi bo'lsa, unda *structure* o'zgaruvchi account qo'ydagi uchta a'zolarga ega bo'ladi.

```
account.balance
account.interestRate
account.term
```

Birinchi ikkita o'zgaruvchi *double* toifa va oxirgi o'zgaruvchi *int* toifadir. Bu a'zo o'zgaruvchilar xuddi shu turdagi boshqa har qanday o'zgaruvchi kabi ishlatilishi mumkin. Misol uchun, yuqoridagi a'zo o'zgaruvchilarga quyidagi uchta o'zlashtirishni amalga oshirish orqali qiymat berish mumkin.

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
	BankAccount account;

	account.balance = 1000.0;

	count.interestRate = 4.7;

	account.term = 11;
}
```

Azo o'zgaruvchilar oddiy o'zgaruvchilar singari har qanday usullarda ishlatilishi mumkin. Misol uchun, yuqorida ko'rgan dasturimizning quyidagi qatorida `account.balance` a'zo o'zgaruvchisining qiymatini odatiy o'zgaruvchi `interest` qiymatiga qo'shadi va keyin natijani yana a'zo o'zgaruvchi `account.balance`ga o'zlashtiradi.

```
account.balance = account.balance + interest;
```

Huddi shu usulda yani nuqta (.) operatori yordamida *class*ning a'zo funksiyalaridan ham foydalanish mumkin. Bu yerda faqat farq shundaki, *structure*ning a'zolari funksiya emas balki o'zgaruvchilardir. *Class*ning a'zo o'zgaruvchilari va a'zo funksiyalari haqida keyingi bo'limlarimizda ko'rib chiqamiz.

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

Yuqorida ko'rgan misolimizdagi ko'rganimiz kabi bir xil nom ostida a'zo o'zgaruvchilarga ega bo'lish *structure*lar uchun muammo tug'dirmaydi. Misol uchun, ikkita *structure*ning o'zgaruvchilarini quydagicha e'lon qilsak

```
FertilizerStock superGrow;
CropYield apples;
```

unda `superGrow`ning `quantitiy` qiymati `superGrow.quantity` a'zo o'zgaruvchisiga va `apples`ning `quantitiy` qiymati `apple.quantitiy` a'zo o'zgaruvchisiga o'zlashtiriladi. Nuqta operatori va *structure*ning a'zo o'zgaruvchisi har bir holatda qaysi qiymat nazarga tutilayotganini belgilab beradi.

*Structure*ning qiymatini a'zo qiymatlarning to'plami sifatida ko'rish mumkin. *Structure*ning qiymatida ko'plab qiymatlar mavjud bo'lishi mumkin. *Structure*ning qiymatini yagona (murakkab) qiymat sifatida ham ko'rish mumkin (yani, a'zo qiymatlardan tashkel topgan yagona qiymat). Shunday qilib *structure*ning qiymatini yagona qiymat sifatida ko'rish mumkin bo'lganligi sababli, *structure*ning qiymati va o'zgaruvchisini c++ dasturlash tilida mavjud bo'lgan *int* yoki *double* kabi oddiy o'zgaruvchi va oddiy qiymatlar singari ishlatish mumkin. Ayniqsa, tenglik belgisi (=) yordamida *structure*ning qiymatini ham o'zlashtirish mumkin. Misol uchun, agar `apple` va `orange` yuqorida ko'rganimiz `GropYield` *structure*ning o'zgaruvchilar bo'ladigan bo'lsa, unda quydagi amal mutlaqo c++ dasturi uchun qoniniy bo'ladi:

```
apples = oranges;
```

Bu o'zlashtirish amali quydagi misolga tengdir:

```
apples.quantity = oranges.quantity;
apples.size = oranges.size;
```

Biz *structure*ning qiymatini shunaqa yusunda o'zlashtirishimiz **sayoz nusxalash** (**shallow copy**) deb ataladi. Bu degani har bir a'zo o'zgaruvchilar to'g'ridan to'g'ni o'zlashtiriladi. Va bu oddiy o'zgaruvchilar uchun muammo tug'dirmaydi. Lekin bu o'zgaruvchilar dinamik o'zgaruvchilar bo'lganda (dinamik taqsimlangada) muammo olib kelishi mumkin. Bu haqda keyingi bo'limlarimizda batafsil ko'rib chiqamiz.

## Class
