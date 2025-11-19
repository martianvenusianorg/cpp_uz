# *Class*

## *Class* tarifi va A'zo Funksiyalar

*Class* bu o'zgaruvchilari *object* (obyekt) bo'lgan *data type* (ma'lumot turi)dir. Shu sababdan c++ dasturlash tilida *class* tushinchasi o'zgaruvchilari qanaqa turdagi qiymatlarga ega bo'lishi va qolaversa a'zo *function* (funksiya)lari nima ekanligini tasvirlaydigan *data type* tushinchasiga tegishli bo'lishi kerak. *Structure* tushinchasi shu narsalarni bazilarini tasvirlaydi. *Structure* foydalanuvchi tomonidan yaratiladigan tur bo'lib a'zo o'zgaruvchilarini yaratish orqali *structure* turidagi qiymatlarini yaratishingizga imkon beradi. *Structure*dan *class*ni keltirib chiqarish uchun, shunchaki qiladigan ishingiz bu bazi a'zo funksiyalari qo'shishdir.

Oddiy *class*ga misol Dastur 1 da ko'rsatilgan. U yearda qiymatlari Yanvar 1 yoki Iyul 4 kabi kun va oy bo'lgan obyektni ifodalaydigan `DayOfYear` nomli *class* ifodalangan. Bu qiymatlar bayramlar, tug'ilgan kun yoki boshqa muhim kunlarni saqlashda ishlatilishi mumkin. Bu yerda `DayOfYear`ni ifodalashda oy *int* turi bilan ifodalangan va bu yearta 1 raqami yanvarni, 2 raqami fevral oyini va boshqa oylarni ham shunaqa raqamlar bilan ifodalash mumkin. Oy kunlari ikkinchi *int* a'zo o'zgaruvchida qayt etiladi. *Class* `DayOfYear` yagona `output` deb nomlangan a'zo funksiyaga ega. Va bu funksiya argumentlariga ega emas va oy va kunlarning qiymatini ekranga chiqaradi. Keling bu `DayOfYear` *class*ning tarifini batafsil ko'rib chiqamiz.

`DayOfYear` *class*imizning tarifi Dastur 1 ning yuqori qismida ko'rsatilgan. Hozircha *keyword  `public`ga e'tibor bermaymiz. Bu shunchaki *`public`* *keyword*i bilan kelgan a'zo o'zgaruvchilar yoki a'zo funksiyalar hech qanday checklashlarga ega emas degani. Bu haqida keyingi bo'limlarimizda bilib olasiz. `DayOfYear` *class*imiz `struct` so'zi o'rnig `class` so'zini ishlatishini hisobga olmaganda uning qolgan qismi *structure* tarifiga juda o'xshaydi va *structure* kabi a'zo funksiya `output` va qolaversa o'zo o'zgaruvchilar `month` va `day`ni birin-ketin ifodalaydi. Bu yearda e'tibor berishimiz kerak bo'lgan narsa bu a'zo funksiya `output`ning faqatgina funksiya e'lon qilinishi bilangina yakunlanishidir. Funksiyaning tarifi esa biror boshqa joyda beriladi. (C++ dasturlash tilida *class* tariflashda a'zo o'zgaruvchiar va a'zo funksiyalarning tartibini siz xohlagant artibda aralashtirib yozishingiz mumkin, biroq biz a'zo funksiyalarni a'zo o'zgaruvchilardan oldin qo'yish ananasiga sodiq qolamiz). *Class* toifadagi obyektlar (ya'ni, o'zgaruvchidir) dasturlash tilida mavjud bo'lgan turlar va *structure* o'zgaruvchilar kabi bir xil tarzda e'lon qilinadi.

---

DASTUR 1

```cpp
// class example_1.cpp
// Bu dastur juda oddiy classga misolnidir.
// Yana ham yaxshiroq misol uchun example_2.cpp da ko'rsatilgan.
#include <iostream>
using namespace std;
class DayOfYear {
  public:
    void output();
    int month;
    int day;
};

int main() {
    DayOfYear today, birthday;

    cout << "Bugungi kunni kiriting:\n ";
    cout << "Oyni raqam bilan kiriting (1-12): ";
    cin >> today.month;
    cout << "Kunni raqam bilan kiriting (1-31): ";
    cin >> today.day;  

    cout << "Tug'ilgan sanangizni kiriting:\n ";
    cout << "Oyni raqam bilan kiriting (1-12): ";
    cin >> birthday.month;
    cout << "Kunni raqam bilan kiriting (1-31): ";
    cin >> birthday.day;

    cout << "Bugungi kun: ";
    today.output();
    cout << "Sizning tug'ilgan sanangiz: ";  
    today.output();

    if (today.month == birthday.month && today.day == birthday.day) {
        cout << "Tug'ilgan kuningiz muborak bo'lsin!" << endl;
    } else {
        cout << "Kuningiz hayrli bo'lsin!" << endl;
    }

    return 0;
}

// Bu output funksiyasi va u DayOfYear classga tegishlidir.
// iostreamdan foydalaniladi.
void DayOfYear::output() 
{
    cout  <<"Oy: " << month
          <<", kun: " << day << endl;
}
```

```
Bugungi kunni kiriting:
 Oyni raqam bilan kiriting (1-12): 1
Kunni raqam bilan kiriting (1-31): 31
Tug'ilgan sanangizni kiriting:
 Oyni raqam bilan kiriting (1-12): 1
Kunni raqam bilan kiriting (1-31): 31
Bugungi kun: Oy: 1, kun: 31
Sizning tug'ilgan sanangiz: Oy: 1, kun: 31
Tug'ilgan kuningiz muborak bo'lsin!
```

```
martianvenusian@MacBookPro class % ./example_1
Bugungi kunni kiriting:
 Oyni raqam bilan kiriting (1-12): 11
Kunni raqam bilan kiriting (1-31): 19
Tug'ilgan sanangizni kiriting:
 Oyni raqam bilan kiriting (1-12): 1
Kunni raqam bilan kiriting (1-31): 31
Bugungi kun: Oy: 11, kun: 19
Sizning tug'ilgan sanangiz: Oy: 11, kun: 19
Kuningiz hayrli bo'lsin!
```

*Class* uchun yaratgan funksiyangizni chaqirish dasturlash tilida mavjud bo'lgan funksiyalarni chaqirish bilan bir hil amalga oshiriladi. Misol uchun, Dastur 1da `DayOfYear` turidagi ikkita obyektni quydagicha e'lon qilinganini ko'rishimiz mumkin:

```
DayOfYear today, birthday;
```

`today` uchun a'zo funksiya `output`ni quydagicha chaqirishimiz mumkin:

```
today.output();
```

va `birthday` uchun a'zo funksiya `output`ni quydagicha chaqirishimiz mumkin:

```
birthday.output();
```

A'zo funksiyaga tarif berilayotganda funksiya tarifi *class* nomini o'z ichiga olishi kerak bo'ladi. Chunki ikki yoki undan ortiq *class*lar bir xil nomli a'zo funksiyalarga ega bo'lishi mumkin. Dastur 1da faqat bitta *class* tarifi berilgan, lekin boshqa holatlarda `output` nomli a'zo funksiyasiga ega bo'lgan ko'plab *class*larni yaratishingiz mumkin.  `DayOfYear` *class*ining `output` a'zo funksiyasning tarifi Dastur 1da ko'rsatilgan. Bu funnksiya tarif oddiy funksiya tarifi bilan bir xil, biroq u yerda bazi farqlar mavjud.

`output` funksiyasining funksiya tarifining boshlanishi quydagichadir:

```
void DayOfYear::output()
```

:: operatori ingliz tilida **scope resolution operator** deb nomlanadi va nuqta operatori bilan o'xshash maqsadda xizmat qiladi. Bu ikkala operatorlar a'zo funksiyalar nimaning a'zosi ekanligini bilish uchun ishlatiladi.

Biroq, :: operator *class* nomi bilan ishlatiladi, . operatori esa obyektlar (ya'ni, *class*ning o'zgaruvchisi) uchun ishlatiladi. :: operatori bilan kelgan *class* ko'pincha **type qualifier** (tur saralovchisi) deb nomlanadi. Chunki u funksiyaning nomini ma'lum bir turga ixtisoslashtiradi.

Dastur 1da berilgan `DayOfYear::output` a'zo funksiyasining tarifiga qarang. Agar e'tibor bersangiz biz u yearda `DayOfYear::output` funksiyasining tarifida `month` va `day` a'zo nomlarni obyektning o'zi va nuqta operatorisiz ishlatyapmiz. Bu ko'ringani kabi unchalik ham g'alati narsa emas. Shu nuqtada biz shunchaki `output` a'zo funksiyaga tarif beryapmiz.Bu tarif `DayOfYear` turidagi barcha obyektlarga bu tarifni qo'llashimiz mumkin, biroq ayni shu nuqtada biz keyinchalik ishlatadigan `DayOfYear` turidagi obyekt nomlarini bilmaymiz, shuning uchun ularning nomlarini berolmaymiz. Qachonki a'zo funksiya quydagicha chaqirilganda:

```
today.output()
```

funksiya tarifidagi barcha a'zo nomlar chaqirayotgan obyektning nomiga ixtisoslashtirilgan bo'ladi. Shuning uchun yuqorida funksiya chaqiruvi quyidagi bilan bir xil dir:

```
cpp
{
    cout  <<"Oy: " << month
          <<", kun: " << day << endl;
}
```

A'zo funksiyaning funksiya tarifini yaratayotganingizda siz ushbu *class*ning barcha a'zolari (barcha ma'lumot a'zolari va funksiya a'zolari) nomlarini nuqta operatorisiz ishlatishingiz mumkin.

---

> ### A'zo Funksiyani Tariflash
>
> A'zo funktsiyasi faqat funktsiya boshida keladigan ClassNomi va :: operatorini hisobga olmaganda boshqa istalgan funktsiya kabi yaratiladi.
>
> ### **SINTAKSIS**
>
> ```
> QaytariladiganTur ClassNomi::FunksiyaNomi(ParameterlarRo'yxati)
> {
> 	FunksiyaTanasiBayonnomasi
> }
> ```
>
> ### MISOL
>
> ```
> // iostreamdan foydalaniladi.
> void DayOfYear::output()
> {
>     cout  <<"Oy: " << month
>           <<", kun: " << day << endl;
> }
> ```
>
> Yuqoridagi DASTUR 1da berilgan `DayOfYear` *class* tarifi misolida, bu yerda `month` va `day` `DayOfYear` *class*i uchun *class* a'zolari o'zgaruvchilar nomlari sifatida belgilanadi. Eslatib o'tamiz, `month` va `day` hech qanday obyekt nomi va nuqta nuqta operatoridan keyin kelmayapti.


---

> ### Nuqta Operatori va Skop Rezolyutsiyasi Operatori
>
> Bu ikki operator a'zo nomlar bilan birga ishlatilib nimaga mansubligini bildirish uchun ishlatiladi. Misol uchun, siz `DayOfYear` deb nomlangan *class*ni e'lon qildingiz va `today` deb nomlangan obyektni quydagicha e'lon qilasiz:
>
> ```
> DayOfYear today;
> ```
>
> Siz `today` obyektining a'zosini belgilash uchun **nuqta operatori**dan foydalanasiz. Misol uchun, `output` `DayOfYear` *class*ining a'zo funksiyasi va quydagi funksiya chaqiruvhi `today` obyektida mavjud bo'lgan ma'lumotlar qiymatlarini chiqaradi:
>
> ```
> today.output();
> ```
>
> Siz biror bir a'zo funksiya uchun funksiya tarifini berayotganingizda *class* nomini belgilash uchun **skop rezolyutsiyasi operatoridan** foydalanasiz. Misol uchun, `output` a'zo funksiyasi uchun funksiya tarifini berayotganingizda funksiyaning boshi quydagicha bo'ladi:
>
> ```
> void DayOfYear::output()
> ```
>
> Eslab qoling, skop rezolyutsiyasi operatori :: *class* nomi bilan ishlatiladi, biroq nuqta operatori shu classning obyekti bilan ishlatiladi.



## *Public* va *Private* A'zolar
