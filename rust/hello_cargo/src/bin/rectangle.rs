#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

fn main() {
    let rect0 = Rectangle {
        width: 30,
        height: 50,
    };

    println!("rect0 is {:#?}", dbg!(&rect0));
    println!("area is {}", dbg!(rect0.area()));

    let rect1=Rectangle::square(30);
    println!("rect1 is {:#?}", &rect1);
}

impl Rectangle {
    /// Returns the area of this [`Rectangle`].
    fn area(&self) -> u32 {
        self.height * self.width
    }

    fn square(size: u32) -> Self {
        Self {
            width: size,
            height: size,
        }
    }
}
