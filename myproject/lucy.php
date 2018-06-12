<! DOCTYPE html>
<html>

<head>
<title>Water Calculator</title>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" type="text/css" href="style.css">
</head>

<body>

<div class="ex2">

<div class="main">

<div class="sidenav">
<a href="http://172.19.194.49/student4/myproject/bmi.html">BMI Calculator</a>
<a href="http://172.19.194.49/student4/myproject/water.html">Water Intake</a>
</div>

<center>
<h1>Welcome!</h1>
<h2>Let's Calculate how much water you need to drink in a day.</h2>
</center>

<b>But first, please input some information about you:</b>

<?php
	$name = $age = $gender = $weight = $result = ""; 

	if ($_SERVER["REQUEST_METHOD"] == "POST") {
  	  $name = test_input($_POST["name"]);
	  $gender = test_input($_POST["gender"]);
	  $age = test_input($_POST["age"]);
	  $weight = test_input($_POST["weight"]);
	}

	function test_input($data) {
	  $data = trim($data);
	  $arg2 = stripslashes($data);
	  $data = htmlspecialchars($data);
	  return $data;
	}
?>

<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
Name:<input type="text" name="name"><br>
Gender (please type M or F):<input type="text" name="gender"><br>
Age: <input type="text" name="age"><br>
Weight (in pounds): <input type="text" name="weight"><br>
<input type="submit" value="Calculate">
</form>

<?php

echo "<b>Your input:</b> <br>";
echo "Name: $name <br>";
echo "Gender: $gender <br>";
echo "Age: $age <br>";
echo "Weight: $weight <br> pounds";

?>

<br>
<br>
<br>

<b>How much water you need:</b>



</body>
</html>
