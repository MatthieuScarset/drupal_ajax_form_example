<?PHP
    $to  = $_POST['to'];
    $from = $_POST['from'];
    $subject = $_POST['subject'];
    $message = $_POST['message'];
    $headers  = 'MIME-Version: 1.0' . "\r\n";
    $headers .= 'Content-type: text/html; charset=iso-8859-1' . "\r\n";
    $headers .= 'To: ' . $to . "\r\n";
    $headers .= 'From: ' . $from . "\r\n";
    mail($to, $subject, $message, $headers);
    header('Location: ' . $_SERVER['HTTP_REFERER']);
