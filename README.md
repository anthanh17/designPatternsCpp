Design Patterns C++
===================

# Singleton Patterns
- Đôi khi trong phân tích thiết kế 1 hệ thống, ta mong muốn có những đối tượng cần tồn tại duy nhất và có thể truy xuất ở mọi lúc mọi nơi.
- Thay vì sử dụng biến toàn cục và static =>> Singleton Patterns
- Mục đích đảm bảo chỉ có thể tạo ra tối đa 1 `Obj` của 1 class cho dù ta cố gắng tạo mới bao nhiêu đối tượng đi nữa.
- `Sử dụng Singleton khi nào:`
    + Đẩm bảo chỉ có 1 instance của class
    + Quản lý việc truy cập tốt hơn vì chỉ có 1 thể hiện duy nhất
    + Có thể quản lý số lượng thể hiện của class trong giới hạn chỉ định.

# Factory Patterns
- Gồm 2 patterns:
    + Factory Method
    + Abstract Factory


1. Factory Method
- Quản lý và trả về các đối tượng theo yêu cầu, giúp việc khoẻi tạo đối tượng 1 cách linh hoạt hơn.
- Việc tạo đối tượng không để lộ logic tạo đối tượng ở phía người dùng và tham chiếu đến đối tượng mới được tạo bằng cách sử dụng interface chung
- Factory Method được sử dụng khi có 1 class cha (super class)
 với nhiều class con (sub class) dựa trên đầu vào và phải trả về 1 trong những class con đó
 - `Sử dụng Factory Method khi:`
    + Có 1 super class với nhiều class con và dựa trên đầu vào, ta cần trả về 1 class con. Mô hình này đưa trách nhiệm khởi tạo 1 class từ phía người dùng sang class Factory
    + Ta không biết sau này sẽ cần đến những class con nào nữa. Khi cần mở rộng, ta chỉ cần tạo sub class và implement thêm vào factory method cho việc khởi tạo sub class này

2. Abstract Factory
- Nó là phương pháp tạo ra một Super-factory dùng để tạo ra các Factory khác. Hay còn được gọi là Factory của các Factory. Abstract Factory Pattern là một Pattern cấp cao hơn so với Factory Method Pattern.
- Trong Abstract Factory pattern, một interface có nhiệm vụ tạo ra một Factory của các object có liên quan tới nhau mà không cần phải chỉ ra trực tiếp các class của object. Mỗi Factory được tạo ra có thể tạo ra các object bằng phương pháp giống như Factory pattern.
- Hãy tưởng tượng, Abstract factory như là một nhà máy lớn chứa nhiều nhà máy nhỏ, trong các nhà máy đó có những xưởng sản xuất, các xưởng đó tạo ra những sản phẩm khác nhau.
- Lợi ích:
    + Cung cấp hướng tiếp cận với Interface thay thì các implement, che giấu sự phức tạp của việc khởi tạo các đối tượng với người dùng (client), độc lập giữa việc khởi tạo đối tượng và hệ thống sử dụng
    + Giúp tránh được việc sử dụng điều kiện logic bên trong Factory Pattern. Khi một Factory Method lớn (có quá nhiều sử lý if-else hay switch-case), chúng ta nên sử dụng theo mô hình Abstract Factory để dễ quản lý hơn (cách phân chia có thể là gom nhóm các sub-class cùng loại vào một Factory).

# Builder Patterns
