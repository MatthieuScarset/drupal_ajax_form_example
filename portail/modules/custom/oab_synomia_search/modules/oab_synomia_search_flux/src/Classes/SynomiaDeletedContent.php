<?php

namespace Drupal\oab_synomia_search_flux\Classes;

use Drupal\Core\Database\Database;


class SynomiaDeletedContent
{

    private $nid;
    private $contentType;
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
     * @param new_nid
     */
    public function setNid($new_nid) {
        $this->nid = $new_nid;
    }

    /** Get ContentType
     * @return mixed
     */
    public function getContentType() {
        return $this->contentType;
    }

    /** Set ContentType
     * @param $new_content_type
     */
    public function setContentType($new_content_type) {
        $this->contentType = $new_content_type;
    }

    /** Get URL
     * @return mixed
     */
    public function getUrl() {
        return $this->url;
    }

    /** Set Url
     * @param $new_url
     */
    public function setUrl($new_url) {
        $this->url = $new_url;
    }

    /** Get language
     * @return mixed
     */
    public function getLanguage() {
        return $this->language;
    }

    /** Set language
     * @param $new_nid
     */
    public function setLanguage($new_language) {
        $this->language = $new_language;
    }

    /** Get deleted
     * @return mixed
     */
    public function getDeleted() {
        return $this->deleted;
    }

    /** Set Deleted
     * @param $new_deleted
     */
    public function setDeleted($new_deleted) {
        $this->deleted = $new_deleted;
    }


    public function save() {
        if (!empty($this->nid)
            && !empty($this->contentType)
            &&!empty($this->url)
            && !empty($this->language)
            && !empty($this->deleted)) {
            $query = Database::getConnection()->merge('synomia_deleted_content')
                ->key(array('nid' => $this->nid))
                ->fields(array(
                    'nid' => $this->nid,
                    'content_type' => $this->contentType,
                    'url' => $this->url,
                    'language' => $this->language,
                    'deleted' => $this->deleted
                ))
                ->execute();
        }
    }

    public function delete() {
        if (!empty($this->nid)
            && !empty($this->contentType)
            && !empty($this->language)) {
            $query = Database::getConnection()->delete('synomia_deleted_content')
                ->condition('nid',$this->nid,'=')
                ->condition('content_type',$this->contentType,'=')
                ->condition('language',$this->language,'=')
                ->execute();
        }
    }
}
