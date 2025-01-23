fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use log::{debug, error, info, trace, warn};

    #[test]
    fn test_log() {
        log4rs::init_file("./src/env.yaml", Default::default()).unwrap();

        error!("This is an error message");
        warn!("This is a warning message");
        info!("This is an info message");
        debug!("This is a debug message");
        trace!("This is a trace message");
    }
}

#[cfg(test)]
mod tests2 {
    use log::{debug, error, info, trace, warn};

    #[test]
    fn test_log() {
        log4rs::init_file("./src/env.yaml", Default::default()).unwrap();

        error!("This is an error message");
        warn!("This is a warning message");
        info!("This is an info message");
        debug!("This is a debug message");
        trace!("This is a trace message");
    }
}
