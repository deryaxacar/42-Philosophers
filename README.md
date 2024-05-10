<!-- Proje Başlığı -->
<h1 align="center">42 - Philosophers</h1>

<!-- Proje Açıklaması -->
<p align="center">
  Bu proje, klasik "Felsefecilerin Yemek Problemi"ni simüle eder. Bu problem, bir grup felsefecinin yuvarlak bir masada oturup belirli kural ve kısıtlamalar altında yemek yemeye çalıştığı bir senaryoyu içerir. Felsefeciler, yemek yemek ve düşünmek için sırayla hareket ederken senkronizasyon, kilitlenme (deadlock) ve açlık (starvation) gibi problemlerin üstesinden gelmeye çalışır. Bu proje, paralel programlama, senkronizasyon ve iş parçacığı yönetimi konusunda deneyim kazanmanıza yardımcı olmayı hedefler.
</p>

<!-- Proje Logosu veya Görseli -->
<p align="center">
  <a target="blank"><img src="https://i.hizliresim.com/xtvqc35.png" height="150" width="150" /></a>
</p>

<!-- Projenin Amacı -->
## Projenin Amacı
<p>
  Bu proje, iş parçacıkları arasındaki senkronizasyonu, kritik kaynaklara erişim sırasında ortaya çıkabilecek sorunları ve bu tür sorunların çözülmesini anlamanıza yardımcı olmayı amaçlar. Proje, çeşitli senkronizasyon tekniklerini ve bu tekniklerin farklı senaryolarda nasıl uygulandığını incelemenize olanak tanır.
</p>

<p>Projenin başlıca amaçları şunlardır:</p>
<ul>
  <li><strong>Senkronizasyon Mekanizmalarını Anlamak:</strong> Felsefecilerin çatal paylaşımı ve senkronizasyon sırasında karşılaşabileceği problemleri analiz etmek.</li>
  <li><strong>Kilitlenme ve Açlığı Önlemek:</strong> Kilitlenme veya açlık durumlarının neden meydana geldiğini anlamak ve bunları önlemek için kullanılan teknikleri öğrenmek.</li>
  <li><strong>İş Parçacığı Yönetimi:</strong> Paralel çalışan iş parçacıklarının kritik bölgelerde güvenli bir şekilde etkileşimde bulunmasını sağlamak.</li>
</ul>

<!-- Proje Açıklaması -->
## Proje Açıklaması
<p>
  Felsefecilerin yemek yemesi için belirli kurallar uygulanır. Bir masada oturan felsefecilerin her biri yemek yemek için yanlarındaki çatalı almak zorundadır. Ancak masada her iki felsefecinin arasında bir çatal bulunduğundan, çatal paylaşımı sırasında senkronizasyon sorunları ortaya çıkabilir. Senkronizasyon sorunları, bir veya daha fazla felsefecinin yemek yiyememesine veya düşünememesine yol açabilir.
</p>

<p>Bu projede, çeşitli senkronizasyon stratejileri kullanılarak kilitlenme ve açlık sorunları çözülmeye çalışılır. İşte bazı senkronizasyon mekanizmaları:</p>
<ul>
  <li><strong>Kilitleme (Locking):</strong> Çatalın alınması ve bırakılması sırasında kilit kullanılır. Bu, aynı anda birden fazla iş parçacığının çatalı almamasını sağlar.</li>
  <li><strong>Semafor:</strong> Semaforlar, bir kaynağın kullanılabilirliğini kontrol etmek için kullanılır ve felsefecilerin çatalı alma sırasını düzenler.</li>
  <li><strong>Kritik Bölge Yönetimi:</strong> Felsefecilerin güvenli bir şekilde çatal alıp bırakmasını sağlamak için kritik bölgeler oluşturulur ve bu alanlara erişim kontrol edilir.</li>
</ul>

<!-- Kullanım Senaryoları -->
## Kullanım Senaryoları
<p>Bu projeyi kullanarak farklı senaryoları deneyimleyebilirsiniz. İşte bazı önerilen kullanım senaryoları ve her birinin detayları:</p>

## 1: Belirli Sayıda Felsefeciyle Simülasyonu Başlatma
Simülasyonu başlatırken, felsefeci sayısını belirlemek önemlidir. Daha fazla felsefeci, senkronizasyon sorunlarını artırabilir. Önerilen kullanım adımları şunlardır:

1. **Felsefeci Sayısını Seçin:** Simülasyon başlarken kaç felsefeciyle çalışacağınızı belirleyin. Felsefeci sayısı arttıkça senkronizasyon zorlukları da artar.
2. **Simülasyonu Başlatın:** Seçilen felsefeci sayısıyla simülasyonu çalıştırın ve senkronizasyon sorunlarını gözlemleyin.
3. **Çıktıyı Analiz Edin:** Simülasyon çıktısını inceleyin. Felsefecilerin yemek yeme ve düşünme sürelerini kontrol edin. Kilitlenme ve açlık gibi durumları gözlemleyin.

## 2: Kilitleme Stratejilerini Test Etme
Farklı kilitleme stratejilerini test etmek, kilitlenme ve açlık durumlarını önlemede yardımcı olabilir. Bu senaryoda, kilitleme tekniklerini değiştirerek felsefecilerin davranışını gözlemleyin:

1. **Kilitleme Stratejisini Değiştirin:** Farklı kilitleme teknikleri kullanarak çatal alma ve bırakma süreçlerini değiştirin. Örneğin, mutex kilitleme, semafor veya başka bir senkronizasyon yöntemi kullanabilirsiniz.
2. **Simülasyonu Tekrar Çalıştırın:** Kilitleme stratejisini değiştirdikten sonra simülasyonu yeniden çalıştırın. Felsefecilerin çatal alma davranışını ve senkronizasyonu gözlemleyin.
3. **Sonuçları Karşılaştırın:** Farklı kilitleme stratejileriyle elde edilen sonuçları karşılaştırın. Kilitlenme veya açlık durumlarının nasıl etkilendiğini inceleyin.

## 3: Farklı Senkronizasyon Mekanizmalarını Deneyin
Senkronizasyon sorunlarını çözmek için çeşitli mekanizmalar kullanılabilir. Bu senaryoda, farklı senkronizasyon mekanizmalarını deneyerek en iyi çözümü bulmaya çalışın:

1. **Farklı Senkronizasyon Mekanizmalarını Seçin:** Mutex kilitleme, semaforlar, kritik bölgeler gibi çeşitli senkronizasyon tekniklerini kullanarak simülasyonu deneyin.
2. **Simülasyonu Çalıştırın ve Gözlemleyin:** Seçilen senkronizasyon mekanizmasıyla simülasyonu çalıştırın. Felsefecilerin davranışını gözlemleyin ve senkronizasyon sorunlarını analiz edin.
3. **En İyi Mekanizmayı Belirleyin:** Çeşitli senkronizasyon mekanizmalarının sonuçlarını karşılaştırın. En iyi senkronizasyon stratejisini bulmaya çalışın.

## 4: Senkronizasyon Sorunlarını ve Çözüm Önerilerini Analiz Edin
Bu senaryoda, ortaya çıkan senkronizasyon sorunlarını analiz ederek uygun çözüm önerilerini belirleyin:

1. **Senkronizasyon Sorunlarını Belirleyin:** Simülasyon sırasında meydana gelen kilitlenme veya açlık gibi sorunları tanımlayın. Felsefecilerin hangi durumlarda bu sorunları yaşadığını gözlemleyin.
2. **Çözüm Önerilerini Araştırın:** Bu sorunları önlemek için kullanılan farklı çözüm önerilerini araştırın. Örneğin, kilitlenme önleme algoritmaları veya felsefeciler için öncelik düzenlemeleri.
3. **Uygun Çözümleri Uygulayın:** Belirlediğiniz çözüm önerilerini simülasyonda uygulayın ve sonucu gözlemleyin. Çözüm önerilerinin senkronizasyon sorunlarını nasıl etkilediğini analiz edin.

<!-- Katkıda Bulunma -->
## Katkıda Bulunma
<p>Bu projeye katkıda bulunmak için aşağıdaki adımları takip edin:</p>
<ol>
  <li><strong>Fork Yapın:</strong> Projeyi kendi GitHub hesabınıza fork yapın ve değişiklikler yapmak için kendi kopyanızı oluşturun.</li>
  <li><strong>Değişiklikler Yapın:</strong> Kendi ortamınızda geliştirmeler yapın ve değişikliklerinizi test edin.</li>
  <li><strong>Pull Request Gönderin:</strong> Değişikliklerinizi göndermek için bir pull request oluşturun ve açıklamalar ekleyin.</li>
</ol>

<!-- Lisans -->
## Lisans
<p>Bu proje, <a href="LICENSE">MIT Lisansı</a> kapsamında lisanslanmıştır. Lisans detaylarını öğrenmek için lütfen lisans dosyasını kontrol edin.</p>
