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

## Class
