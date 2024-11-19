// Get the next message from e.g. a file.
// Getting a message might fail for some reason and there might be no message available.
fn get_next_message() -> Result<Option<String>, ()> {
    use std::sync::Mutex;

    // Use lazy_static to create a static mutable variable.
    // Rust does not allow mutable static variables without using unsafe.
    lazy_static::lazy_static! {
        static ref MESSAGE_AVAILABLE: Mutex<bool> = Mutex::new(true);
    }

    let mut message_available = MESSAGE_AVAILABLE.lock().unwrap();

    if *message_available {
        *message_available = false;
        Ok(Some("Hello, world!".to_string()))
    } else {
        Ok(None)
    }

    // The Mutex is automatically unlocked when it goes out of scope via its Drop implementation.
}

fn main() -> Result<(), ()> {
    loop {
        match get_next_message() {
            Ok(Some(message)) => {
                println!("Message: {}", message);
            }
            Ok(None) => {
                println!("No message available");
                break;
            }
            Err(_) => {
                println!("Error: get_next_message() failed");
                return Err(());
            }
        }
    }

    println!("End of program\n");
    Ok(())
}
