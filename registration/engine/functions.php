<?php if (!defined("DARKCORECMS")) safe_redirect("");
//--Powered by DarkCoreCMS
//--Website: http://mmltools.com
//--Author: Max aka (Darksoke)

class Register{
    public $errors = array();
    public function __construct(&$username, &$password, &$repassword)
    {
        $this->register_user($username, $password, $repassword);
    }
    private function connect(){
        global $configuration;
        $con = mysqli_connect("localhost", "USERHERE", "PASSHERE", "realmd");
        if (!$con) {
            printf("Connect failed: %s\n", mysqli_connect_error());
            exit();
        }
        return $con;
    }
    private function register_user($username, $password, $repassword){
	$upper_username = strtoupper($username);
        if ($password != $repassword)
            array_push($this->errors, "Passwords does not match");
        if($this->check_user_exist($upper_username))
            array_push($this->errors, "Username is already in use");
        if(empty($this->errors)) {
            $password = encrypt($upper_username, $password);
            $sql = "INSERT INTO `account` (`username`, `sha_pass_hash`) VALUES (?,?)";
	    $con = $this->connect();
            if ($stmt = $con->prepare($sql)) {
                $stmt->bind_param("ss", $upper_username, $password);
                $stmt->execute();
		$stmt->close();
		safe_redirect("?success={$username}");
            }
        }
    }
    private function check_user_exist($username){
        $sql = "SELECT username FROM account WHERE `username`=?";
	$con = $this->connect();
        if ($stmt = $con->prepare($sql)) {
            $stmt->bind_param("s", $username);
            $stmt->execute();
            $result = $stmt->get_result();
	    if($result->num_rows > 0)
		return true;
        }
        return false;
    }
}
