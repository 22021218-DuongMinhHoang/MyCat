# Bài tập lớn lập trình nâng cao - INT2215 1

- Họ và tên: Dương Minh Hoàng
- MSV: 22021218
- Lớp: K67CB

## Giới thiệu game
- Tên: MyCat
- Tổng quát: Người chơi mới nuôi một chú mèo, điều cần làm bây giờ là chăm sóc người bạn mới thật tốt.
### Hướng dẫn chơi:
- Mèo: có 6 thuộc tính: Age, Full, Poo, Health, Love, Sick.
  - Age: là tuổi của mèo tính từ lúc mới nuôi là 0, Age tăng lên 1 mỗi 2 ngày.
  - Full: là độ no của mèo, Full giảm đến 1 mức thì mèo sẽ đói và tự động đến chỗ ăn.
  - Poo: là độ buồn đi vệ sinh cảu mèo, Poo sẽ tăng sau khi mèo ăn xong và khi đến 1 mức nào đó thì mèo sẽ tự động đi đến hộp cát để đi vệ sinh, lúc đo Poo sẽ về 0.
  - Health: là sức khỏe của mèo, Health có thể tăng khi ăn, khi đi vệ sinh, khi tập thể dục.
  - Love: là mức độ yêu mến của mèo với chủ, Love có thể tăng khi ăn, khi vuốt ve.
  - Sick: là bệnh mèo mắc phải, khi không có bệnh thì Sick là No, khi mèo mắc bệnh Sick là Yes, có 3 loại bệnh: Hunger, Diarrhea, Alpha
  
- Màn hình game có 4 phần: Place, Phone, Interact, Note.
- Place: là nơi hiện tại nhân vật người chơi đang ở, có 4 Place là: House, Shop, Work, Vet.
  - House: là nhà ở của nhân vật và là nơi diễn ra các hoạt động chính là nuôi mèo.
  - Shop: là nơi mà người chơi có thể đến để mua thức ăn và thuốc cho mèo.
  - Work: là nơi nhân vật chính đi làm để kiếm tiền nuôi bản thân và mèo.
  - Vet: là nơi mang mèo đến để chữa bệnh.
  - Có thể di chuyển tới các Place khác nhau bằng Map trong Phone.
- Phone: là điện thoại của nhân vật người chơi, có 4 App trên điện thoại: MyMeo, MeoTip, ZooTube, Map
  - MyMeo: theo dõi tuổi, tình hình sức khỏe và độ yêu mến của mèo
