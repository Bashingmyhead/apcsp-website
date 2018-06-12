<! DOCTYPE html>
<html>

<head>
<link rel="icon" href="https://sites.google.com/a/my.sduhsd.net/csp-yana2319/home/0-01-magic-square/water.jpg?attredirects=0">
<link rel="stylesheet" type="text/css" href="style.css">
<title>Water Calculator</title>
<meta name="viewport" content="width=device-width, initial-scale=1">
</head>

<body>
<div class="text">

<div class="ex2">

<div class="main">

<div class="sidenav">
<a href="http://172.19.194.49/student4/myproject/bmi.php">BMI Calculator</a>
<a href="http://172.19.194.49/student4/myproject/water.php">Water Intake</a>
</div>

<center>
<h1> Welcome! </h1>
<h2>Let's calculate how much water you need to drink in a day.</h2>
</center>

<br>

<center>
<img src ="https://sites.google.com/a/my.sduhsd.net/csp-yana2319/home/0-01-magic-square/drink.jpg?attredirects=0" width="400" height ="300"><br>
</center>

<br>

<center><b>But first, please input some information about you:</b></center>

<br>

<?php
	$name = $age = $gender = $weight = $result = ""; 

	if ($_SERVER["REQUEST_METHOD"] == "POST") {
  	  $name = test_input($_POST["name"]);
	  $gender = test_input($_POST["gender"]);
	  $age = test_input($_POST["age"]);
	  $weight = test_input($_POST["weight"]);
	  exec("/usr/lib/cgi-bin/student4/water " . $gender . " " . $weight , $result);
	}

	function test_input($data) {
	  $data = trim($data);
	  $data = stripslashes($data);
	  $data = htmlspecialchars($data);
	  return $data;
	}
?>

<center>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
<label for="name">Name:</label><br>
<input type="text" id="name" name="name"><br>
<label for="gender"> Gender (please type M or F):</label><br>
<input type="text" id="gender" name="gender"><br>
<label for="age">Age:</label><br>
<input type="text" name="age"><br>
<label for="weight">Weight (in pounds):</label><br>
<input type="text" name="weight"><br>
<input type="submit" value="Calculate"><br>
</form></center>

<?php

echo "<b>Your input:</b> <br>";
echo "Name: $name <br>";
echo "Gender: $gender <br>";
echo "Age: $age <br>";
echo "Weight: $weight pounds<br><br>";

echo "<b>How much water you need:</b><br><br>";

foreach ($result as $line) {
echo $line;
}
echo " <br> <br> <br>";

?>

<br>
<br>

</div>
</div>
</div>
</body>
</html>
