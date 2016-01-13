Konvoy Bulma<br/>
Arazi üzerindeki düşman ordu konvoylarının bulunması üzerine bir program geliştirilecektir. İlgili arazi ve üzerindeki konvoylar kuşbakışı şeklinde 25x80 lik bir dizi içerisinde tutulacaktır. Bu dizi içinde ‘-‘ karakteri arazinin boş kısımlarını, ‘*(yıldız)’ karakteri ise düşman konvoyu formasyonunu göstermektedir. İlgili dizi “arazi.txt” isimli bir metin dosyasından okutulacaktır. Tehlikeli düşman konvoyu formasyonları ise “konvoy_formasyonu.txt” isimli bir metin dosyasından okutulacak ve 15x15 boyutlarında bir karakter dizisinde tutulacaktır. Konvoy formasyonunda ‘-‘ karakteri boşluk, ‘*(yıldız)’ karakteri asker ve “+” karakteri ise konvoy komutanını belirtmektedir. “konvoy_formasyonu.txt” isimli dosyanın ilk satırında, dosyada yer alan konvoy sayısı bulunmaktadır. İlk satırdan sonra, 1 satır konvoy kodu (tamsayı) ve 15 satır konvoy formasyonu olmak üzere
düşman konvoyları bulunmaktadır.<br/>
Bir konvoy formasyonu, diziye alındıktan sonra arazi dizisinde aratılacaktır. Bunun için formasyonda yıldız ve artı karakterleri ile gösterilen asker ve komutanlar , arazi dizisinde yıldız karakterleri ile gösterilen askerlerle eşleştirilecektir. Formasyondaki tüm yıldızlar, arazi dizisinin bir bölümündeki yıldızlarla eşleştirilirse; konvoy kodu ve bu konvoyun komutanının bulunduğu satır ve sütun koordinatları yazdırılmalıdır (sol-üst köşenin koordinatı 1,1 şeklindedir).<br/>
Not: Eşleştirme sırasında dikkatli olunmalı, sadece formasyondaki yıldızlar ile arazi dizisindeki yıldızlar eşleştirilmelidir. Formasyonda yer almayan ancak arazi dizisindeki askerlerin yakınlarında başka askerler olabilir, bu eşleştirmeyi bozmaz (aşağıdaki örnek çalıştırmada verilen 5 kodlu konvoya bakınız).ÖRNEK ÇALIŞTIRMA:<br/><br/>
“arazi.txt” dosyası:<br/>
--------------------------------------------------------------------------------<br/>
--------------------------------------------------------------------------------<br/>
-------------*(yıldız)------------------------------------------------------------*(yıldız)-----<br/>
------------------*(yıldız)-------------------------------------------------------------<br/>
-------*(yıldız)-------------------------------------*(yıldız)----------------------------------<br/>
------------------*(yıldız)-------------------------------------------------------------<br/>
-------------*(yıldız)------------------------------------------------------------------<br/>
--------------------------------------------------------------------------------<br/>
------------*(yıldız)-------------------------------------------------------------------<br/>
--------------------------------------------------------------------------------<br/>
-----------*(yıldız)------------------------------------------------------------*(yıldız)-------<br/>
--------------------------------------*(yıldız)-----------------------------------------<br/>
------------*(yıldız)------------------------------------*(yıldız)------------------------------<br/>
--------------------------------------------------------------------------------<br/>
-----------------------------------------*(yıldız)--------------------------------------<br/>
-------------------------------------------*(yıldız)------------------------------------<br/>
---------------------------------------------*(yıldız)----------------------------------<br/>
--------------------------------------------------------------------------------<br/>
------------------------------------------------*(yıldız)-------------------------------<br/>
-------------*(yıldız)------------------------------------------------------------------<br/>
----------------------------------------*(yıldız)-----------------------------------*(yıldız)---<br/>
--------------------------------------------------------------------------------<br/>
--------------------------------------------------------------------------------<br/>
--------------------------------------------------------------------------------<br/>
--------------------------------------------------------------------------------<br/><br/>
“konvoy_formasyonu.txt” dosyası:<br/>
2<br/>
12<br/>
---------------<br/>
---------------<br/>
-+-------------<br/>
------------*(yıldız)--<br/>
---------------<br/>
----*(yıldız)----------<br/>
------*(yıldız)--------<br/>
--------*(yıldız)------<br/>
---------------<br/>
-----------*(yıldız)---<br/>
---------------<br/>
---*(yıldız)-----------<br/>
---------------<br/>
---------------<br/>
---------------<br/>
5<br/>
---------------<br/>
---------------<br/>
---------------<br/>
------+--------<br/>
-----------*(yıldız)---<br/>
---------------<br/>
-----------*(yıldız)---<br/>
------*(yıldız)--------<br/>
---------------<br/>
-----*(yıldız)---------<br/>
---------------<br/>
----*(yıldız)----------<br/>
---------------<br/>
-----*(yıldız)---------<br/>
---------------<br/><br/>
Bu örnek için programın çıktısı şu şekilde olmalıdır:<br/>
Kod Koordinatlar<br/>
--- ------------<br/>
12 (12,39)<br/>
5 (3,14)<br/>
