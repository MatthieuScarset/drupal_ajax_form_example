<?php

namespace Drupal\oab_synomia_search_flux\Classes;

use Drupal\Core\Database\Database;


class SynomiaDeletedContent
{

	private $nid;
	private $content_type;
	private $url;
	private $language;
	private $deleted;

	/** Get le NID
	 * @return mixed
	 */
	public function getNid() {
		return $this->nid;
	}

	/** Set NID
	 * @param $newNid
	 */
	public function setNid($newNid) {
		$this->nid = $newNid;
	}

	/** Get ContentType
	 * @return mixed
	 */
	public function getContentType() {
		return $this->content_type;
	}

	/** Set ContentType
	 * @param $newContentType
	 */
	public function setContentType($newContentType) {
		$this->content_type = $newContentType;
	}

	/** Get URL
	 * @return mixed
	 */
	public function getUrl() {
		return $this->url;
	}

	/** Set Url
	 * @param $newUrl
	 */
	public function setUrl($newUrl) {
		$this->url = $newUrl;
	}

	/** Get language
	 * @return mixed
	 */
	public function getLanguage() {
		return $this->language;
	}

	/** Set language
	 * @param $newNid
	 */
	public function setLanguage($newLanguage) {
		$this->language = $newLanguage;
	}

	/** Get deleted
	 * @return mixed
	 */
	public function getDeleted() {
		return $this->deleted;
	}

	/** Set Deleted
	 * @param $newDeleted
	 */
	public function setDeleted($newDeleted) {
		$this->deleted = $newDeleted;
	}


	public function save() {
		if (!empty($this->nid)
			&& !empty($this->content_type)
			&&!empty($this->url)
			&& !empty($this->language)
			&& !empty($this->deleted)) {
			$query = Database::getConnection()->merge('synomia_deleted_content')
				->key(array('nid' => $this->nid))
				->fields(array(
					'nid' => $this->nid,
					'content_type' => $this->content_type,
					'url' => $this->url,
					'language' => $this->language,
					'deleted' => $this->deleted
				))
				->execute();
		}
	}

	public function delete() {
		if (!empty($this->nid)
			&& !empty($this->content_type)
			&& !empty($this->language)) {
			$query = Database::getConnection()->delete('synomia_deleted_content')
				->condition('nid',$this->nid,'=')
				->condition('content_type',$this->content_type,'=')
				->condition('language',$this->language,'=')
				->execute();
		}
	}
}
