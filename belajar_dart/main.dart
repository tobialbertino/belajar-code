Future<void> main() async {
  print('Fetching username...');
  var username = fetchUsername();
  print('You are logged in as $username');
  print('Welcome!');
}

Future<String> fetchUsername() {
  return Future.delayed(Duration(seconds: 3), () => 'DartUser');
}
