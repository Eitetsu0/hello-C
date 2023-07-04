fn main() {
    let mut s1 = gives_ownership();         // gives_ownership 将返回值
                                        // 转移给 s1
    println!("s1={s1}");
    s1.push_str(",xx");
    println!("s1={s1}");
    let r1=&mut s1;
    // 无法同时创建两个可变借用，会报错
    // let r2=&mut s1;
    r1.push_str(",r1");
    //引用的作用域从声明的地方开始一直持续到最后一次使用为止
    //下文不再使用r1的情况下，下行不报错
    let r2=&mut s1;
    r2.push_str(",r2");
    println!("s1={s1}");

    let s2 = String::from("hello");     // s2 进入作用域

    println!("s2={s2}");

    let s3 = takes_and_gives_back(s2);     // s2 被移动到
                                                    // takes_and_gives_back 中，
                                                    // 它也将返回值移给 s3
    println!("s3={s3}");
    let s3 = takes_and_gives_back(s3);
    println!("s3={s3}");
    takes_and_gives_back(s3);

} // 这里，s3 移出作用域并被丢弃。s2 也移出作用域，但已被移走，
  // 所以什么也不会发生。s1 离开作用域并被丢弃

fn gives_ownership() -> String {             // gives_ownership 会将
                                             // 返回值移动给
                                             // 调用它的函数

    let some_string = String::from("yours"); // some_string 进入作用域。

    some_string                              // 返回 some_string 
                                             // 并移出给调用的函数
                                             // 
}

// takes_and_gives_back 将传入字符串并返回该值
fn takes_and_gives_back(a_string: String) -> String { // a_string 进入作用域
                                                      // 

    a_string  // 返回 a_string 并移出给调用的函数
}
