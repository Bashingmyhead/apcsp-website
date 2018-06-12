<! DOCTYPE html>
<html>

<head>
<link rel="icon" href="https://sites.google.com/a/my.sduhsd.net/csp-yana2319/home/0-01-magic-square/water.jpg?attredirects=0">
<link rel="stylesheet" type="text/css" href="style.css">
<title>BMI Calculator</title>
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
<h1> HELLO! </h1>
<h2> Want to Calculate your BMI? </h2>
<b>Please input some information about yourself:</b>
</center>

<?php
	$name = $age = $gender = $heightft = $heightin = $weight = "";

 if ($_SERVER["REQUEST_METHOD"] == "POST") {
          $name = test_input($_POST["name"]);
          $gender = test_input($_POST["gender"]);
          $age = test_input($_POST["age"]);
	  $heightft = test_input($_POST["heightft"]);
	  $heightin = test_input($_POST["heightin"]);
          $weight = test_input($_POST["weight"]);
          exec("/usr/lib/cgi-bin/student4/bmi " . $heightft . " " . $heightin . " " . $weight . " " . $age . " " . $gender , $result);
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

<label for="heightft">Height (ft):</label><br>
<input type="text"  name="heightft"><br>

<label for="heightin">Height (in):</label><br>
<input type="text"  name="heightin"><br>

<label for="weight">Weight (in pounds):</label><br>
<input type="text" name="weight"><br>

<input type="submit" value="Calculate"><br>
</form></center>

<?php

echo "<b>Your input:</b> <br> <br>";
echo "Name: $name <br>";
echo "Gender: $gender <br>";
echo "Age: $age <br>";
echo "Height(ft): $heightft <br>";
echo "Height(in): $heightin <br>";
echo "Weight: $weight  (lbs)<br>";

echo "<b>Your BMI:";

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
