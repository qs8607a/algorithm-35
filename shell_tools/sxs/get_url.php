<?php

$keystart = "<a href=";

$fp = fopen("php://stdin", "r");

while ($line = fgets($fp, 300000))
{
	$sub1 = strstr($line, $keystart);

	if($sub1=="")continue;

	while ($sub1 != "")
	{
		$line = substr($sub1, 8, strlen($sub1)-8);

		if(Ereg("[^ \f\n\r\t\v]+", $line, $reg))
		{
			printf("%s\n", $reg[0]);
		}

		$sub1 = strstr($line, $keystart);
	}

}

?>
