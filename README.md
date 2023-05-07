# Bài tập lớn lập trình nâng cao - INT2215 1

- Họ và tên: Dương Minh Hoàng
- MSV: 22021218
- Lớp: K67CB

# Giới thiệu game: 
- Tên: MyCat
- Tổng quát: Người chơi mới nuôi một chú mèo, điều cần làm bây giờ là chăm sóc người bạn mới thật tốt.
- Thể loại game: Point & Click.
- Các tính năng: mèo sẽ di chuyển khắp nơi trong phòng, mèo cũng có thể làm trò, người chơi có thể tương tác với mèo, mua đồ, các hoạt động cần thiết để nuôi mèo, có hình ảnh và âm thanh tương ứng với các hành động, có thể chơi lại.
## Hướng dẫn chơi:
- Mèo: có 6 thuộc tính: Age, Full, Poo, Health, Love, Sick. Trong đó người chơi không thể biết Full, Poo và loại bệnh mèo đang mắc phải.
  - Age: là tuổi của mèo, tính từ lúc mới nuôi là 0, Age tăng lên 1 mỗi 2 ngày.
  - Full: là độ no của mèo, Full giảm đến 1 mức thì mèo sẽ đói và tự động đến chỗ ăn.
  - Poo: là độ buồn đi vệ sinh cảu mèo, Poo sẽ tăng sau khi mèo ăn xong và khi đến 1 mức nào đó thì mèo sẽ tự động đi đến hộp cát để đi vệ sinh, lúc đo Poo sẽ về 0.
  - Health: là sức khỏe của mèo, Health có thể tăng khi ăn, khi đi vệ sinh, khi tập thể dục, khi Health của mèo giảm dưới 0, mèo chết, Game Over.
  - Love: là mức độ yêu mến của mèo với chủ, Love có thể tăng khi ăn, khi vuốt ve.
  - Sick: là bệnh mèo mắc phải, khi không có bệnh thì Sick là No, khi mèo mắc bệnh Sick là Yes, có 3 loại bệnh: Hunger, Diarrhea, Alpha.
      - Khi Yes: Health của mèo sẽ giảm từ từ.
      - Hunger: là bệnh đói, Full sẽ giảm nhanh làm Mèo thấy đói nhanh.
      - Diarrhea: là tiêu chảy, Poo sẽ tăng nhanh làm mèo đi vệ sinh liên tục.
      - Alpha: là virus, Health của mèo sẽ tụt nhanh. 
- Màn hình game có 4 phần: Note, Place, Phone, Interact.
- Note: hiện lên ghi chú về lượng đồ mà người chơi đang có và ngày trôi qua: Day, Money, CatFood, 5 loại Pill.
  - Day: số ngày trôi qua kể từ khi nuôi mèo.
  - Money: số tiền hiện có, dùng để mua đồ, có thể kiếm bằng Work hoặc ZooTube, -6 tiền sinh hoạt của nhân vật người chơi mỗi ngày.
  - CatFood: thức ăn cho mèo.
  - Pill: thuốc cho mèo, 5 loại Pill: E, P, Q, A, PQA.
    - Pill E: tăng Health.
    - Pill P: chữa Hunger.
    - Pill Q: chữa Diarrhea.
    - Pill A: chữa Alpha.
    - Pill PQA: tổng hợp công dụng của 3 loại Pill trên.
- Place: là nơi hiện tại nhân vật người chơi đang ở, có 4 Place là: House, Shop, Work, Vet.
  - House: là nhà ở của nhân vật và là nơi diễn ra các hoạt động chính là nuôi mèo.
  - Shop: là nơi mà người chơi có thể đến để mua thức ăn và thuốc cho mèo.
  - Work: là nơi nhân vật chính đi làm để kiếm tiền nuôi bản thân và mèo.
  - Vet: là nơi mang mèo đến để chữa bệnh.
  - Có thể di chuyển tới các Place khác nhau bằng Map trong Phone.
- Phone: là điện thoại của nhân vật người chơi, có 4 App trên điện thoại: MyMeo, MeoTips, ZooTube, Map.
  - MyMeo: theo dõi Age, Health, Sick và Love của (Sick chỉ thể hiện Yes hoặc No chứ không thể hiện loại bệnh, người chơi phải tự chẩn đoán).
  - MeoTips: thể hiện các mẹo khi nuôi mèo.
  - ZooTube: nền tảng video lớn nhất thế giới động vật, có thể đăng video mèo lên đó để kiếm thêm chút tiền.
  - Map: giúp người chơi di chuyển qua các Place.
- Interact: người chơi tương tác với mèo, có 9 loại tương tác: FillBowl, CleanLitterBox, Pet, Excerise và 5 loại DrinkPill.
  - FillBowl: đổ đầy vào bát thức ăn cho mèo, -1 CatFood.
  - CleanLitterBox: làm sạch hộp cát mèo.
  - Pet: vuốt ve mèo.
  - Excercise: giúp mèo tập thể dục.
  - DrinkPill: uống 1 trong 5 loại thuốc, nếu uống loại thuốc không phù hợp với bệnh đang mắc, Health sẽ giảm.
- ZooTube đóng trước 21:00, các Place sẽ đóng trước 22:00, mèo sẽ đi ngủ lúc 22:00, nhân vật người chơi đi ngủ lúc 23:00, ngày mới bắt đầu lúc 6:00.
- GameOver khi Health nhỏ hơn 0: hiện lên Love, Age và lời nhắn của mèo tới người chơi. 
## Các kĩ thuật được sử dụng:
- Sử dụng thư viện SDL, SDL_image, SDL_ttf, SDL_mixer.
- Áp dụng thuật toán A* để mèo tìm đường đi ngắn nhất tới nơi mà nó muốn.
- Kĩ thuật tách file.
## Đánh giá chủ quan:
- Tích cực: game khá dễ thương, hình ảnh và âm thanh vui nhộn.
- Tiêu cực: game có nhiều chức năng cần lưu ý, nếu đã nắm bắt được rồi lại cảm thấy khá nhàm, con mèo chạy nhảy linh tinh có thể gây khó chịu.
- Kinh nghiệm và bài học rút ra:
  - Học được cách tách file, cách dùng SDL và cách dùng GitHub.
  - Rút ra kinh nghiệm quản lí và sắp xếp thời gian, xây dựng kế hoạch.
  - Rèn luyện được khả năng tự học, tự tìm hiểu và khả năng lập trình.
